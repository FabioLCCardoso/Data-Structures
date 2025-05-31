import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.lang.foreign.AddressLayout;
import java.util.ArrayList;
import java.util.List;

public class GraphGUI extends JFrame {
    private Graph graph;
    private List<Vertex> vertices;
    private List<Edge> edges;
    private List<Edge> mstEdges;
    private CanvasPanel canvas;
    private Vertex selectedVertex1;
    private Vertex selectedVertex2;
    private boolean addingEdge;
    private boolean addingVertex;
    private JTextArea outputArea;
    private final int MAX_VERTICES = 20;
    private boolean isAdded = false;
    private boolean KrushkalUsed = false;

    // Vertex class to store position and label
    private static class Vertex {
        int id;
        int x, y;

        Vertex(int id, int x, int y) {
            this.id = id;
            this.x = x;
            this.y = y;
        }
    }

    // Edge class for GUI
    private static class Edge {
        int src, dest, weight;

        Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    // Canvas for drawing graph
    private class CanvasPanel extends JPanel {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2d = (Graphics2D) g;
            g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            // Draw edges
            g2d.setColor(Color.BLACK);
            for (Edge edge : edges) {
                Vertex v1 = vertices.get(edge.src);
                Vertex v2 = vertices.get(edge.dest);
                DrawLine(g2d, edge, v1, v2);
            }

            // Draw MST edges in green
            g2d.setColor(Color.GREEN);
            for (Edge edge : mstEdges) {
                Vertex v1 = vertices.get(edge.src);
                Vertex v2 = vertices.get(edge.dest);
                g2d.setStroke(new BasicStroke(2));
                DrawLine(g2d, edge, v1, v2);
                g2d.setStroke(new BasicStroke(1));
            }

            // Draw vertices
            g2d.setColor(Color.BLUE);
            for (Vertex v : vertices) {
                g2d.fillOval(v.x - 15, v.y - 15, 30, 30);
                g2d.setColor(Color.WHITE);
                g2d.drawString(String.valueOf(v.id), v.x - 5, v.y + 5);
                g2d.setColor(Color.BLUE);
            }
            if(KrushkalUsed){
                g2d.setColor(Color.RED);
                for (Vertex v : vertices) {
                    g2d.fillOval(v.x - 15, v.y - 15, 30, 30);
                    g2d.setColor(Color.WHITE);
                    g2d.drawString(String.valueOf(v.id), v.x - 5, v.y + 5);
                    g2d.setColor(Color.RED);
                }
            }
        }

        private void DrawLine(Graphics2D g2d, Edge edge, Vertex v1, Vertex v2) {
            g2d.drawLine(v1.x, v1.y, v2.x, v2.y);
            int midX = (v1.x + v2.x) / 2;
            int midY = (v1.y + v2.y) / 2;
            g2d.drawString(String.valueOf(edge.weight), midX, midY);
        }
    }

    public GraphGUI() {
        setTitle("Graph Builder for Kruskal's Algorithm");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        vertices = new ArrayList<>();
        edges = new ArrayList<>();
        mstEdges = new ArrayList<>();
        addingEdge = false;
        selectedVertex1 = null;
        selectedVertex2 = null;
        graph = new Graph(MAX_VERTICES);

        // Create canvas
        canvas = new CanvasPanel();
        canvas.setBackground(Color.WHITE);

        // Control panel
        JPanel controlPanel = new JPanel();
        JButton textInputButton = new JButton("Text Input Graph");
        JButton addVertexButton = new JButton("Add Vertex");
        JButton addEdgeButton = new JButton("Add Edge");
        JButton runKruskalButton = new JButton("Run Kruskal's");
        JButton clearButton = new JButton("Clear Graph");
        controlPanel.add(textInputButton);
        controlPanel.add(addVertexButton);
        controlPanel.add(addEdgeButton);
        controlPanel.add(runKruskalButton);
        controlPanel.add(clearButton);

        // Output area
        outputArea = new JTextArea(10, 50);
        outputArea.setEditable(false);
        JScrollPane outputScroll = new JScrollPane(outputArea);

        // Layout
        setLayout(new BorderLayout());
        add(controlPanel, BorderLayout.NORTH);
        add(canvas, BorderLayout.CENTER);
        add(outputScroll, BorderLayout.SOUTH);

        // Add vertex on click (for manual mode)
        canvas.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if (!addingEdge && addingVertex) {
                    int id = vertices.size();
                    if (id >= MAX_VERTICES) {
                        JOptionPane.showMessageDialog(GraphGUI.this, "Maximum vertices reached!");
                        return;
                    }
                    vertices.add(new Vertex(id, e.getX(), e.getY()));
                    canvas.repaint();
                    addingVertex = false;
                } else {
                    for (Vertex v : vertices) {
                        if (Math.abs(v.x - e.getX()) < 25 && Math.abs(v.y - e.getY()) < 25) {
                            if (selectedVertex1 == null) {
                                selectedVertex1 = v;
                            } else if (selectedVertex2 == null && v != selectedVertex1) {
                                selectedVertex2 = v;
                                String weightStr = JOptionPane.showInputDialog(
                                        GraphGUI.this,
                                        "Enter weight for edge (" + selectedVertex1.id + "," + selectedVertex2.id + "):",
                                        "1"
                                );
                                try {
                                    int weight = Integer.parseInt(weightStr);
                                    if (weight > 0) {
                                        graph.addEdge(selectedVertex1.id, selectedVertex2.id, weight);
                                        edges.add(new Edge(selectedVertex1.id, selectedVertex2.id, weight));
                                        addingEdge = false;
                                        canvas.repaint();
                                    }
                                } catch (NumberFormatException ex) {
                                    JOptionPane.showMessageDialog(GraphGUI.this, "Invalid weight!");
                                }
                                selectedVertex1 = null;
                                selectedVertex2 = null;

                            }
                            break;
                        }
                    }
                }
            }
        });

        // Text input button
        textInputButton.addActionListener(e -> {
            // Clear existing graph
            vertices.clear();
            edges.clear();
            mstEdges.clear();
            graph = new Graph(MAX_VERTICES);
            outputArea.setText("");

            // Prompt for number of vertices
            String vertexStr = JOptionPane.showInputDialog(
                    GraphGUI.this,
                    "Enter the number of vertices (MAX 20):",
                    "3"
            );
            int nVertices;
            try {
                nVertices = Integer.parseInt(vertexStr);
                if (nVertices < 1 || nVertices > MAX_VERTICES) {
                    JOptionPane.showMessageDialog(this, "Enter a number between 1 and 20!");
                    return;
                }
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this, "Invalid number!");
                return;
            }

            // Place vertices in a circular layout
            int centerX = canvas.getWidth() / 2;
            int centerY = canvas.getHeight() / 2;
            int radius = Math.min(canvas.getWidth(), canvas.getHeight()) / 3;
            for (int i = 0; i < nVertices; i++) {
                double angle = 2 * Math.PI * i / nVertices;
                int x = (int) (centerX + radius * Math.cos(angle));
                int y = (int) (centerY + radius * Math.sin(angle));
                vertices.add(new Vertex(i, x, y));
            }

            // Prompt for edge weights for all pairs (i,j) and (j,i)
            for (int i = 0; i < nVertices; i++) {
                for (int j = 0; j < nVertices; j++) {
                    if (i != j) { // Skip self-loops
                        String weightStr = JOptionPane.showInputDialog(
                                GraphGUI.this,
                                "Enter the weight of edge (" + i + "," + j + ") (0 if no edge):",
                                "0"
                        );
                        try {
                            int weight = Integer.parseInt(weightStr);
                            if (weight < 0) {
                                JOptionPane.showMessageDialog(this, "Weight must be non-negative!");
                                return;
                            }
                            if (weight > 0) {
                                int[][] adjMatrix = graph.getMatrix();
                                if (adjMatrix[i][j] != graph.INF() && adjMatrix[i][j] != 0) {
                                    JOptionPane.showMessageDialog(this,
                                            "Edge (" + i + "," + j + ") already exists with weight " + adjMatrix[i][j] + "!");
                                    continue; // Skip adding if edge exists
                                }
                                isAdded = false;
                                for(Edge edge: edges) {
                                    if (edge.src == i && edge.dest == j || edge.src == j && edge.dest == i) {
                                        isAdded = true;
                                        break;
                                    }
                                }
                                if(isAdded) {
                                    JOptionPane.showMessageDialog(this,
                                            "Edge (" + i + "," + j + ") already exists in the display!");
                                    continue; // Skip adding if edge exists
                                }

                                graph.addEdge(i, j, weight);
                                graph.addEdge(j, i, weight);
                                isAdded = true;
                                edges.add(new Edge(i, j, weight));
                                }





                        } catch (NumberFormatException ex) {
                            JOptionPane.showMessageDialog(this, "Invalid weight!");
                            return;
                        }
                    }
                }
            }

            canvas.repaint();
            outputArea.setText("Graph created. Click 'Run Kruskal's' to compute the MST.");
        });

        // Other button actions
        addVertexButton.addActionListener(e -> {
            addingEdge = false;
            addingVertex = true;
            selectedVertex1 = null;
            selectedVertex2 = null;
            outputArea.setText("Click on the canvas to add a vertex.");
        });

        addEdgeButton.addActionListener(e -> {
            if (vertices.size() < 2) {
                JOptionPane.showMessageDialog(this, "Need at least 2 vertices to add an edge!");
                return;
            }
            addingEdge = true;
            addingVertex = false;
            selectedVertex1 = null;
            selectedVertex2 = null;
            outputArea.setText("Click two vertices to add an edge between them.");
        });

        runKruskalButton.addActionListener(e -> {
            if (vertices.isEmpty()) {
                JOptionPane.showMessageDialog(this, "No vertices in the graph!");
                return;
            }
            mstEdges.clear();
            outputArea.setText("");
            java.io.PrintStream originalOut = System.out;
            System.setOut(new java.io.PrintStream(new java.io.OutputStream() {
                @Override
                public void write(int b) {
                    outputArea.append(String.valueOf((char) b));
                }
            }));
            try{
                List<Krushkal.Edge> mst = Krushkal.findMST(graph, vertices.size());
                System.setOut(originalOut);

                for(Krushkal.Edge edge: mst){
                    mstEdges.add(new Edge(edge.src, edge.dest, edge.weight));
                }
                KrushkalUsed = true;
                canvas.repaint();
                outputArea.append("MST edges computed successfully!");
            }catch(Exception ex){
                System.setOut(originalOut);
                outputArea.append("Error: " + ex.getMessage());
            }



            /*Krushkal.findMST(graph);
            System.setOut(originalOut); */

            // Extract MST edges for visualization
           /* int[][] adjMatrix = graph.getMatrix();
            for (int i = 0; i < vertices.size(); i++) {
                for (int j = i + 1; j < vertices.size(); j++) {
                    if (adjMatrix[i][j] != graph.INF() && adjMatrix[i][j] != 0) {
                        for (Krushkal.Edge mstEdge : getMSTEdges()) {
                            if ((mstEdge.src == i && mstEdge.dest == j) || (mstEdge.src == j && mstEdge.dest == i)) {
                                mstEdges.add(new Edge(i, j, adjMatrix[i][j]));
                            }
                        }
                    }
                }
            }
            KrushkalUsed = true;
            canvas.repaint();

            */
        });

        clearButton.addActionListener(e -> {
            addingVertex = false;
            vertices.clear();
            edges.clear();
            mstEdges.clear();
            graph = new Graph(MAX_VERTICES);
            outputArea.setText("");
            KrushkalUsed = false;
            canvas.repaint();
        });
    }

    /* // Helper to get MST edges
    private List<Krushkal.Edge> getMSTEdges() {
        List<Krushkal.Edge> mst = new ArrayList<>();
        java.util.PriorityQueue<Krushkal.Edge> edgesPQ = new java.util.PriorityQueue<>();
        int[][] adjMatrix = graph.getMatrix();
        int nVERTICES = vertices.size();
        for (int i = 0; i < nVERTICES; i++) {
            for (int j = i + 1; j < nVERTICES; j++) {
                if (adjMatrix[i][j] != graph.INF() && adjMatrix[i][j] != 0) {
                    edgesPQ.offer(new Krushkal.Edge(i, j, adjMatrix[i][j]));
                }
            }
        }

        Krushkal.UnionFind uf = new Krushkal.UnionFind(nVERTICES);
        int edgesAdded = 0;
        while (!edgesPQ.isEmpty() && edgesAdded < nVERTICES - 1) {
            Krushkal.Edge edge = edgesPQ.poll();
            if (uf.union(edge.src, edge.dest)) {
                mst.add(edge);
                edgesAdded++;
            }
        }
        return mst;
    } */

}
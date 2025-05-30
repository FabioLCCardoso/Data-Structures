public class Krushkal {

    static class Edge implements Comparable<Edge> {
        int src, dest, weight;

        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return this.weight - o.weight;
        }
    }

    //UnionFind data structure for cycle detection
    static class UnionFind {
        int[] parent, rank;

        public UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        public boolean union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) {
                return false; // Same set, adding edge would create a cycle
            }
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
    }
    public static void findMST(Graph g){
        int nVERTICES = g.size();
        int INF = g.INF();
        UnionFind uf = new UnionFind(nVERTICES);
        java.util.PriorityQueue<Edge> edges = new java.util.PriorityQueue<>();
        int [][] adjMatrix = g.getMatrix();
        for(int i=0;i<nVERTICES;i++){
            for(int j= i + 1 ;j < nVERTICES; j++){
                if(adjMatrix[i][j]!=INF && adjMatrix[i][j] != 0){
                    edges.offer(new Edge( i, j, adjMatrix[i][j]));
                }
            }
        }
        java.util.List<Edge> mst = new java.util.ArrayList<>();
        int totalWeight = 0;
        int edgesAdded = 0;

        while(!edges.isEmpty() && edgesAdded < nVERTICES - 1){
            Edge edge = edges.poll();
            if(uf.union(edge.src, edge.dest)){
                mst.add(edge);
                totalWeight += edge.weight;
                edgesAdded++;
            }
        }
        if(edgesAdded < nVERTICES - 1){
            System.out.println("No MST possible");
            return;
        }

        System.out.println("MST edges:");
        for (Edge edge : mst) {
            System.out.println(edge.src + " -> " + edge.dest + ": " + edge.weight);
        }
        System.out.println("Total weight of MST: " + totalWeight);

        System.out.println("\nEdges not included in the MST:");
        while (!edges.isEmpty()) {
            Edge edge = edges.poll();
            System.out.println(edge.src + " -> " + edge.dest + ": " + edge.weight);
        }

        System.out.println("\nFull MST Edge List:");
        System.out.print("{");
        for (int i = 0; i < mst.size(); i++) {
            Edge edge = mst.get(i);
            System.out.print("(" + edge.src + "," + edge.dest + "," + edge.weight + ")");
            if (i < mst.size() - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("}");
    }
    }




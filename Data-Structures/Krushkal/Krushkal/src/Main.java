//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

//import java.util.*;
import javax.swing.*;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        final int MAX_VERTICES = 20;
        Scanner sc = new Scanner(System.in);

        new GraphGUI().setVisible(true);
        System.out.println("Enter the number of vertices (MAX 20) : ");
        int nVERTICES;
        //Validate input (1 to 20)
        while (true) {
            nVERTICES = sc.nextInt();
            if (nVERTICES >= 1 && nVERTICES <= MAX_VERTICES) {
                break;
            }
            System.out.println("Enter a number between 1 and 20: ");
        }
        //Create graph
        Graph graph = new Graph(nVERTICES);
        //Read edge weights for all vertex pairs, also validates weights to be positive.
        for (int i = 0; i < nVERTICES; i++) {
            for (int j = 0; j < nVERTICES; j++) {
                if (i != j) {
                    System.out.println("Enter the weight of edge (" + i + "," + j + " (0 if no edge) : ");
                    int weight;
                    //validate input
                    while (true) {
                        weight = sc.nextInt();
                        if (weight >= 0) { // Allow 0 for no edge, positive for edges
                            break;
                        }
                        System.out.println("Weight must be a positive integer : ");
                    }

                    if (weight != 0) {
                        graph.addEdge(i, j, weight);
                        graph.addEdge(j, i, weight);
                    }
                }
            }
        }

        //Prompt for source vertex and validate it
        System.out.println("Enter source vertex (0 to " + (nVERTICES - 1) + "): ");
        int src;
        while (true) {
            src = sc.nextInt();
            if (src >= 0 && src < nVERTICES) {
                break;
            }
            System.out.println("Source vertex must be between 0 and " + (nVERTICES - 1) + ": ");
        }
        //Prompt for destination vertex and validate it
        System.out.println("Enter destination vertex (0 to " + (nVERTICES - 1) + "): ");
        int dest;
        while (true) {
            dest = sc.nextInt();
            if (dest >= 0 && dest < nVERTICES) {
                break;
            }
            System.out.println("Invalid input! Destination vertex must be between 0 and " + (nVERTICES - 1) + ": ");
        }

        System.out.println("Type 1 for Dijkstra's algorithm \n Type 2 for Krushkal's algorithm:");

        int op = sc.nextInt();



        switch(op){
        //Run Dijkstra's algorithm'
            case 1:
                Dijkstra.findShortestPath(graph, src, dest);
                break;
        //Run Krushkal's algorithm'
            case 2:
                Krushkal.findMST(graph, nVERTICES);
                break;
            default:
                System.out.println("Invalid input! Please enter 1 or 2");
                break;
        }

        //Dijkstra.findShortestPath(graph, src, dest);
        //Close scanner
        sc.close();
    }
}

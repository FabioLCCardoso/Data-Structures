//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

import java.util.*;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        final int MAX_VERTICES = 20;
        Scanner sc = new Scanner(System.in);


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
        //Run Dijkstra's algorithm'
            Dijkstra.findShortestPath(graph, src, dest);
        //Close scanner
            sc.close();
    }
}


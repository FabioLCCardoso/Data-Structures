public class Dijkstra {

    public static void findShortestPath(Graph g, int src, int dest) {
        int nVERTICES = g.size();
        int INF = g.INF();
        int[] dist = new int[nVERTICES];
        boolean[] visited = new boolean[nVERTICES];
        int[] prev = new int[nVERTICES];

        // Initialize distances and prev array
        for (int i = 0; i < nVERTICES; i++) {
            dist[i] = INF;
            prev[i] = -1;
        }

        dist[src] = 0;

        // Dijkstra's algorithm
        for (int i = 0; i < nVERTICES - 1; i++) {
            //Select unvisited vertex u with minimum distance
            int u = minDistance(dist, visited, nVERTICES, INF);
            if (u == -1) {
                break;
            }

            visited[u] = true;
            //Update distance of adjacent vertices
            for (int v = 0; v < nVERTICES; v++) {
                int weight = g.getWeight(u, v);
                if (!visited[v] && weight != INF && dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                }
            }
        }

        // Print the shortest path
        System.out.print("Shortest path from " + src + " to " + dest + ": ");
        if (src == dest) {
            System.out.println(src + " (same vertex, no path needed)");
            System.out.println("Shortest Distance: 0");
        } else if (dist[dest] == INF) {
            System.out.println("No path exists");
            System.out.println("Shortest Distance: No path");
        } else {
            printPath(g, prev, src, dest);
            System.out.println();
            System.out.println("Shortest Distance: " + dist[dest]);
        }
    }

    private static int minDistance(int[] dist, boolean[] visited, int nVERTICES, int INF) {
        int min = INF, minIndex = -1;
        for (int v = 0; v < nVERTICES; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    private static void printPath(Graph g, int[] prev, int src, int dest) {
        // Build path from dest to src
        java.util.List<Integer> path = new java.util.ArrayList<>();
        for (int v = dest; v != -1; v = prev[v]) {
            path.add(v);
            if (v == src) break; // Stop when source is reached
        }

        // Reverse and print path from src to dest
        if (path.get(path.size() - 1) != src) {
            System.out.print("No valid path");
            return;
        }

        // Print path
        for (int i = path.size() - 1; i >= 0; i--) {
            System.out.print(path.get(i));
            if (i > 0) {
                System.out.print(" -> ");
            }
        }
        // Print weights for each edge
        System.out.print(" (weights: ");
        for (int i = path.size() - 1; i > 0; i--) {
            int from = path.get(i);
            int to = path.get(i - 1);
            int weight = g.getWeight(from, to);
            System.out.print(weight);
            if (i > 1) {
                System.out.print(", ");
            }
        }
        System.out.print(")");
    }
}
public class Graph {
    private final int[][] adjMatrix;
    private final int nVERTICES;
    private final int INF = Integer.MAX_VALUE;

    // Constructor, initializes an nVERTICES x nVERTICES adjacency matrix
    // Sets diagonal (i,i) to 0 and other entries to INF (no edge)
    public Graph(int nVERTICES) {
        this.nVERTICES = nVERTICES;
        adjMatrix = new int[nVERTICES][nVERTICES];
        for (int i = 0; i < nVERTICES; i++) {
            for (int j = 0; j < nVERTICES; j++) {
                adjMatrix[i][j] = (i == j) ? 0 : INF ;
            }
        }
    }
    // Adds an edge from src to dest with weight
    // Overwrites existing weight for edge (src,dest)
    public void addEdge(int src, int dest, int weight) {
        if (adjMatrix[src][dest] == INF && adjMatrix[dest][src] == INF) {
            adjMatrix[src][dest] = weight;
            adjMatrix[dest][src] = weight; // Ensure symmetry
        }
        if(weight == 0){
            adjMatrix[src][dest] = INF;
            adjMatrix[dest][src] = INF;
        }
    }
    //Returns weight of edge (src,dest)
    public int getWeight(int src, int dest) {
        return adjMatrix[src][dest];
    }
    //Returns adjacency matrix
    public int[][] getMatrix(){
        return adjMatrix;
    }
    //Returns number of vertices
    public int size(){
        return nVERTICES;
    }
    //Returns INF constant
    public int INF(){
        return INF;
    }
}
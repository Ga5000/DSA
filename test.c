#include <stdio.h>
#include <stdlib.h>

#define INF 999999 // A large value representing infinity
#define V 20 // Maximum number of vertices in the graph
#define qEdge 3 // Maximum number of edges in the graph

int graph[V][V]; // Adjacency matrix representation of the graph
void initializeGraph(){
    // Initialize the graph with some edges
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            graph[i][j] = 0; // No edges initially
        }
    }

    graph[0][1] = 1; graph[0][2] = 1;
    graph[10][11] = 1;
}

void bicoloration(){
    int color[2] = {50, 51, 52};

    for(int i = 0; i < V; i++){
        int k = 0;
        graph[i][i] = color[k]; // Assign the first color to the vertex
        for(int j = 0; j < V; j++){
            if(graph[i][j] == 1){ // If there is an edge between vertex i and j
                if(graph[i][i] == graph[j][j]){ // If both vertices have the same color
                    k++;
                    graph[i][i] = color[k]; // Assign the next color to vertex i
                    j = 0;
                    if (graph[i][i] == color[2]) {
                        i = V; // Exit the loop if we reach the end of colors
                        j = V;
                        printf("Graph is not bipartite\n");
                        return;
                    }
                }
            }
        }
    }
}

void kColor(){
    int color[V];
    for(int i = 0; i < V; i++){
        color[i] = i; // Initialize all vertices with no color
    }

    for(int i = 0; i < V; i++){
        int k = 0;
        graph[i][i] = color[k]; // Assign the first color to the vertex
        for(int j = 0; j < V; j++){
            if(graph[i][j] == 1){ // If there is an edge between vertex i and j
                if(graph[i][i] == graph[j][j]){ // If both vertices have the same color
                    k++;
                    graph[i][i] = color[k]; // Assign the next color to vertex i
                    j = 0;
                }
            }
        }
    }
}

void dijkstra(int source) {
    int dist[V];
    int visited[V];

    // Initialize all distances as infinite and visited as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count < V; count++) {
        // Pick the unvisited vertex with the smallest distance
        int u = -1;
        int minDist = INF;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // No reachable vertex left
        visited[u] = 1;

        // Relax all adjacent vertices of u
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != NULL && !visited[v]) { // If there is an edge and the vertex is unvisited
                int newDist = dist[u] + graph[u][v]; // Calculate new distance
                // If the new distance is smaller, update it
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }
}

void flood(int vOrigem, int visited[], int flooded[]) {
    flooded[vOrigem] = 1;
    visited[vOrigem] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[vOrigem][i] == 1 && !visited[i]) {
            flood(i, visited, flooded);
        }
    }
}

void startFlood(int vOrigem) {
    int visited[V] = {0};
    int flooded[V] = {0};
    flood(vOrigem, visited, flooded);

    // Optional: print flooded vertices
    for (int i = 0; i < V; i++) {
        if (flooded[i]) {
            printf("Vertex %d is flooded\n", i);
        }
    }
}

int DFS(int vOrigem, int vDestino, int visited[]){
    visited[vOrigem] = 1;
    if(vOrigem == vDestino) {
        return 1; // Path found
    }

    for(int i = 0; i < V; i++){
        if(graph[vOrigem][i] == 1 && !visited[i]){ // If there is an edge and the vertex is unvisited
            if(DFS(i, vDestino, visited)) {
                return 1; // Path found in recursive call
            }
        }
    }

    return 0; // No path found
}


int BFS(int vOrigem, int vDestino){
    int visited[V] = {0};
    int queue[V] = {0};
    int front = 0, rear = 0;

    visited[vOrigem] = 1; 
    queue[rear++] = vOrigem; // Enqueue the origin vertex

    while(front < rear){
        int current = queue[front++];
        if(current == vDestino) {
            return 1; // Path found
        }

        for(int i = 0; i < V; i++){
            if(graph[current][i] == 1 && !visited[i]){
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return 0;
}


int main(void){
    initializeGraph();
    printf("Result: %d\n", BFS(0, 10)); // Example usage: check path from vertex 0 to vertex 3

    return 0;
}
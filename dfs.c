#include <stdio.h>
#include <stdlib.h>

#define V 20 // Maximum number of vertices in the graph

int graph[V][V]; // Adjacency matrix representation of the graph
void initializeGraph(){
    // Initialize the graph with some edges
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            graph[i][j] = 0; // No edges initially
        }
    }

    graph[0][1] = 1; graph[0][2] = 1;
    graph[1][0] = 1; graph[1][3] = 1;
    graph[2][0] = 1; graph[2][3] = 1;
    graph[3][1] = 1; graph[3][2] = 1;
    graph[4][5] = 1; graph[4][6] = 1;
    graph[5][4] = 1; graph[5][7] = 1;
    graph[6][4] = 1; graph[6][7] = 1;
    graph[7][5] = 1; graph[7][6] = 1;
    graph[8][9] = 1; graph[8][10] = 1;
    graph[9][8] = 1; graph[9][11] = 1;
    graph[10][8] = 1; graph[10][11] = 1;
}

int DFS(int vOrigin, int vDestination, int visited[]){ // returns 1 if path exists, 0 otherwise
    visited[vOrigin] = 1; // Mark the current vertex as visited

    if(vOrigin == vDestination) {
        return 1; // Path found
    }

    for(int i = 0; i < V; i++){
        if(graph[vOrigin][i] == 1 && !visited[i]){ // If there is an edge and the vertex is unvisited
            if(DFS(i, vDestination, visited)) {
                return 1; // Path found in the recursive call
            }
        }
    }
    return 0; // No path found
}

int main(void){

    initializeGraph();
    int visited[V] = {0}; // Initialize visited array to keep track of visited vertices
    printf("Result: %d\n", DFS(0, 3, visited)); // Example usage: check path from vertex 0 to vertex 3
    return 0;
}
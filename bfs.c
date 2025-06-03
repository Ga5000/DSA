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

int BFS(int vOrigin, int vDestination){ // returns 1 if path exists, 0 otherwise
    int visited[V];
    int queue[V];
    for(int i = 0; i < V; i++){
        visited[i] = 0; // Mark all vertices as unvisited
        queue[i] = -1; // Initialize queue
    }

    visited[vOrigin] = 1; // Mark the origin vertex as visited	
    int front = 0, rear = 0;

    queue[rear++] = vOrigin; // Enqueue the origin vertex
    while(front < rear){
        int current = queue[front++]; // Dequeue a vertex

        if(current == vDestination) {
            return 1; // Path found
        }

        for(int i = 0; i < V; i++){
            if(graph[current][i] == 1 && !visited[i]){ // If there is an edge and the vertex is unvisited
                visited[i] = 1; // Mark it as visited
                queue[rear++] = i; // Enqueue the vertex
            }
        }
    }
    return 0; // No path found
}

int main(void){

    initializeGraph();
    printf("Result: %d\n", BFS(0, 3)); // Example usage: check path from vertex 0 to vertex 3

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define V 14 // Maximum number of vertices in the graph

int graph[V][V]; // Adjacency matrix representation of the graph

void initializeGraph(){
    // Initialize the graph with some edges
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            graph[i][j] = 0; // No edges initially
        }
    }

    graph[0][1] = 4;  graph[0][2] = 3;
    graph[1][0] = 4;  graph[1][3] = 2;
    graph[2][0] = 3;  graph[2][3] = 5;
    graph[3][1] = 2;  graph[3][2] = 5;
    graph[4][5] = 7;  graph[4][6] = 8;
    graph[5][4] = 7;  graph[5][7] = 6;
    graph[6][4] = 8;  graph[6][7] = 4;
    graph[7][5] = 6;  graph[7][6] = 4;
    graph[8][9] = 2;  graph[8][10] = 9;
    graph[9][8] = 2;  graph[9][11] = 3;
    graph[10][8] = 9; graph[10][11] = 1;
    graph[12][13] = 5; graph[13][12] = 5;
    graph[13][0]  = 7; graph[0][13]  = 7;   
    graph[0][12]  = 6; graph[12][0]  = 6;
}

void prim(int startVertex){
    int selected[V]; // To track selected vertices
    int edges[V][V]; // To store edges of the MST
    int edgeCount = 0;

    for(int i = 0; i < V; i++){
        selected[i] = 0; // Initialize all vertices as unselected
    }

    selected[startVertex] = 1; // Start from the first vertex

    while(edgeCount < V - 1){
        int minWeight = 1000000; // Arbitrary large number
        int u = -1, v = -1;

        for(int i = 0; i < V; i++){
            if(selected[i]){
                for(int j = 0; j < V; j++){
                    if(graph[i][j] && !selected[j] && graph[i][j] < minWeight){
                        minWeight = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(u != -1 && v != -1){
            edges[edgeCount][0] = u;
            edges[edgeCount][1] = v;
            edgeCount++;
            selected[v] = 1; // Mark the new vertex as selected
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for(int i = 0; i < edgeCount; i++){
        printf("Edge %d: %d - %d\n", i + 1, edges[i][0], edges[i][1]);
    }
}

int main(void){
    initializeGraph();
    prim(0); // Run Prim's algorithm to find the Minimum Spanning Tree
    

    return 0;
}
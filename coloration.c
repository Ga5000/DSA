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
    graph[12][13] = 1; graph[13][12] = 1;
    graph[13][0]  = 1; graph[0][13]  = 1;   
    graph[0][12]  = 1; graph[12][0]  = 1;
}

void printGraph(){
    printf("Graph adjacency matrix:\n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void coloration(){
    int i, j, k;
    int color[V];

    for(i = 0; i < V; i++){
        color[i] = 50 + i; 
    }


    for(i = 0; i < V; i++){
        k = 0;
        graph[i][i] = color[k]; // Assign the first color to the vertex

        for(j = 0; j < V; j++){
            if(graph[i][j] == 1){ // If there is an edge between vertex i and j
              if(graph[i][i] == graph[j][j]){ // If both vertices have the same color
                    k++;
                    graph[i][i] = color[k]; // Assign the next color to vertex i
                    j = 0; // Reset j to check all edges again
                }
            }
        }
}
}


int main(void){
    initializeGraph();
    coloration();
    printGraph();
    return 0;
}
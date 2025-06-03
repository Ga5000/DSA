#include <stdio.h>

#define V 7
#define qEdge 20
#define INF __INT_MAX__

struct Edge{
    int vE;
    int vI;
    float weight;
}edge[qEdge];

void initEdgeList();
void dijkstra(const int source);


void initEdgeList(){

    // vertex 0 
    edge[0].vE = 0;
    edge[0].vI = 1;
    edge[0].weight = 6;

    edge[1].vE = 0;
    edge[1].vI = 2;
    edge[1].weight = 1;

    edge[2].vE = 0;
    edge[2].vI = 3;
    edge[2].weight = 5;

    // vertex 1
    edge[3].vE = 1;
    edge[3].vI = 0;
    edge[3].weight = 6;

    edge[4].vE = 1;
	edge[4].vI = 2;
	edge[4].weight = 2;
	
    edge[5].vE = 1;
	edge[5].vI = 4;
	edge[5].weight = 5;

    // vertex 2
    edge[6].vE = 2;
    edge[6].vI = 0;
    edge[6].weight = 1;

    edge[7].vE = 2;
    edge[7].vI = 1;
    edge[7].weight = 2;

    edge[8].vE = 2;
    edge[8].vI = 3;
    edge[8].weight = 2;

    edge[9].vE = 2;
    edge[9].vI = 4;
    edge[9].weight = 6;

    edge[10].vE = 2;
    edge[10].vI = 5;
    edge[10].weight = 4;

    	
	//vertex 3
	edge[11].vE = 3;
	edge[11].vI = 0;
	edge[11].weight = 5;
	
	edge[12].vE = 3;
	edge[12].vI = 2;
	edge[12].weight = 2;
	
	edge[13].vE = 3;
	edge[13].vI = 5;
	edge[13].weight = 4;
	
	// vertex 4
	edge[14].vE = 4;
	edge[14].vI = 1;
	edge[14].weight = 5;
	
	edge[15].vE = 4;
	edge[15].vI = 2;
	edge[15].weight = 6;
	
	edge[16].vE = 4;
	edge[16].vI = 5;
	edge[16].weight = 3;
	
	//vertex 5
	edge[17].vE = 5;
	edge[17].vI = 2;
	edge[17].weight = 4;
	
	edge[18].vE = 5;
	edge[18].vI = 3;
	edge[18].weight = 4;
	
	edge[19].vE = 5;
	edge[19].vI = 4;
	edge[19].weight = 3;
	
}

void dijkstra(const int source){
    int distance[V];
    int visited[V]; // 0 -> false, 1 -> true

    for(int i = 0; i < V; i++){
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[source] = 0;

    for(int count = 0; count < V; count++){
        int minDistance = INF;

        int u = -1; // unvisited node with the minimum distance

        for(int i = 0; i < V; i++){
            if(!visited[i] && distance[i] < minDistance){
                minDistance = distance[i];
                u = i;
            }
        }

        if(u == -1) break; // visited reachable all nodes in the Graph / Edge List

        visited[u] = 1; // mark current (u) as visited

        for(int i = 0; i < qEdge; i++){
            if(edge[i].vE == u){
                int neightboor = edge[i].vI;
                float weight = edge[i].weight;

                if(!visited[neightboor] && distance[u] + weight < distance[neightboor]){ 
                    // if the neighboor was not visited and the distance of the current node plus the weight of the edge to the neighboor is less than the distance to the neighboor
                    distance[neightboor] = distance[u] + weight;
                }
            }
        }

    }

    printf("Shortest distances from node %d:\n", source);
    for (int i = 0; i < V; i++) {
        if (distance[i] == INF)
            printf("Node %d: unreachable\n", i);
        else
            printf("Node %d: %d\n", i, distance[i]);
    }

}

int main(void){
    initEdgeList();
    dijkstra(0);

    return 0;
}
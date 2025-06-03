#include <stdio.h>

#define V 7
#define qEdge 20
#define INF __INT_MAX__

struct Edge {
    int vE;
    int vI;
    float weight;
} edge[qEdge];

void initEdgeList();

void bellmanford(const int source) {
    float distance[V];

    for (int i = 0; i < V; i++)
        distance[i] = INF;

    distance[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < qEdge; j++) {
            int u = edge[j].vE;
            int v = edge[j].vI;
            float w = edge[j].weight;
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    int hasNegativeCycle = 0;
    for (int j = 0; j < qEdge; j++) {
        int u = edge[j].vE;
        int v = edge[j].vI;
        float w = edge[j].weight;
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            hasNegativeCycle = 1;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("Graph contains a negative-weight cycle\n");
    } else {
        printf("Shortest distances from node %d:\n", source);
        for (int i = 0; i < V; i++) {
            if (distance[i] == INF)
                printf("Node %d: unreachable\n", i);
            else
                printf("Node %d: %.0f\n", i, distance[i]);
        }
    }
}

void initEdgeList() {
    // Same as your dijkstra.c
    edge[0].vE = 0; edge[0].vI = 1; edge[0].weight = 6;
    edge[1].vE = 0; edge[1].vI = 2; edge[1].weight = 1;
    edge[2].vE = 0; edge[2].vI = 3; edge[2].weight = 5;
    edge[3].vE = 1; edge[3].vI = 0; edge[3].weight = 6;
    edge[4].vE = 1; edge[4].vI = 2; edge[4].weight = 2;
    edge[5].vE = 1; edge[5].vI = 4; edge[5].weight = 5;
    edge[6].vE = 2; edge[6].vI = 0; edge[6].weight = 1;
    edge[7].vE = 2; edge[7].vI = 1; edge[7].weight = 2;
    edge[8].vE = 2; edge[8].vI = 3; edge[8].weight = 2;
    edge[9].vE = 2; edge[9].vI = 4; edge[9].weight = 6;
    edge[10].vE = 2; edge[10].vI = 5; edge[10].weight = 4;
    edge[11].vE = 3; edge[11].vI = 0; edge[11].weight = 5;
    edge[12].vE = 3; edge[12].vI = 2; edge[12].weight = 2;
    edge[13].vE = 3; edge[13].vI = 5; edge[13].weight = 4;
    edge[14].vE = 4; edge[14].vI = 1; edge[14].weight = 5;
    edge[15].vE = 4; edge[15].vI = 2; edge[15].weight = 6;
    edge[16].vE = 4; edge[16].vI = 5; edge[16].weight = 3;
    edge[17].vE = 5; edge[17].vI = 2; edge[17].weight = 4;
    edge[18].vE = 5; edge[18].vI = 3; edge[18].weight = 4;
    edge[19].vE = 5; edge[19].vI = 4; edge[19].weight = 3;
}

int main(void) {
    initEdgeList();
    bellmanford(0);
    return 0;
}
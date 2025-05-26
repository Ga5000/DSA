#include <stdio.h>
#include <stdlib.h>

#define V 7
#define qEdge 20
#define INF __INT_MAX__

struct Edge{
    int vE;
    int vI;
    float weight;
}edge[qEdge];

struct TSP{
    int combination[V + 1];
    float cost;
};

void initEdgeList();
int factorial(const int n);
float getEdgeCost(int from, int to);
void swap(int* a, int* b);
void generatePermutations(int* arr, int l, int r, int start, int* index);
void tsp(const int vI, int nOfCombinations);

struct TSP* tspCombinations = NULL;

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

void initEdgeList(){
    edge[0] = (struct Edge){0, 1, 6};
    edge[1] = (struct Edge){0, 2, 1};
    edge[2] = (struct Edge){0, 3, 5};
    edge[3] = (struct Edge){1, 0, 6};
    edge[4] = (struct Edge){1, 2, 2};
    edge[5] = (struct Edge){1, 4, 5};
    edge[6] = (struct Edge){2, 0, 1};
    edge[7] = (struct Edge){2, 1, 2};
    edge[8] = (struct Edge){2, 3, 2};
    edge[9] = (struct Edge){2, 4, 6};
    edge[10] = (struct Edge){2, 5, 4};
    edge[11] = (struct Edge){3, 0, 5};
    edge[12] = (struct Edge){3, 2, 2};
    edge[13] = (struct Edge){3, 5, 4};
    edge[14] = (struct Edge){4, 1, 5};
    edge[15] = (struct Edge){4, 2, 6};
    edge[16] = (struct Edge){4, 5, 3};
    edge[17] = (struct Edge){5, 2, 4};
    edge[18] = (struct Edge){5, 3, 4};
    edge[19] = (struct Edge){5, 4, 3};
}

float getEdgeCost(int from, int to) {
    for(int i = 0; i < qEdge; i++) {
        if(edge[i].vE == from && edge[i].vI == to)
            return edge[i].weight;
    }
    return INF;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generatePermutations(int* arr, int l, int r, int start, int* index) {
    if (l == r) {
        tspCombinations[*index].combination[0] = start;
        float cost = 0;
        for (int i = 0; i < r; i++) {
            tspCombinations[*index].combination[i + 1] = arr[i];
            if (i == 0)
                cost += getEdgeCost(start, arr[i]);
            else
                cost += getEdgeCost(arr[i - 1], arr[i]);
        }
        cost += getEdgeCost(arr[r - 1], start);
        tspCombinations[*index].combination[V] = start;
        tspCombinations[*index].cost = cost;
        (*index)++;
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&arr[l], &arr[i]);
        generatePermutations(arr, l + 1, r, start, index);
        swap(&arr[l], &arr[i]);
    }
}

void tsp(const int vI, int nOfCombinations){
    int vertexes[V - 1];
    int index = 0;
    for(int i = 0; i < V; i++){
        if(i != vI)
            vertexes[index++] = i;
    }
    int comboIndex = 0;
    generatePermutations(vertexes, 0, V - 2, vI, &comboIndex);
}

int main(void){
    int nOfCombinations = factorial(V - 1);
    tspCombinations = (struct TSP*) malloc(nOfCombinations * sizeof(struct TSP));
    initEdgeList();
    tsp(0, nOfCombinations);

    for (int i = 0; i < nOfCombinations; i++) {
        printf("Route: ");
        for (int j = 0; j <= V; j++) {
            printf("%d ", tspCombinations[i].combination[j]);
        }
        printf("| Cost: %.2f\n", tspCombinations[i].cost);
    }

    free(tspCombinations);
    return 0;
}
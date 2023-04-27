#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5

int min_key(int key[], int mst_set[]) {
    int min = INT_MAX, min_index, v;
    for (v = 0; v < V; v++) {
        if (mst_set[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void prim(int graph[V][V]) {
    int parent[V], key[V], mst_set[V];
    int i, count, u, v;
    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mst_set[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (count = 0; count < V-1; count++) {
        u = min_key(key, mst_set);
        mst_set[u] = 1;
        for (v = 0; v < V; v++) {
            if (graph[u][v] && mst_set[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printf("Edge   Weight\n");
    for (i = 1; i < V; i++) {
        printf("%d - %d    %d\n", parent[i], i, graph[parent[i]][i]);
    }
}

int main() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    prim(graph);
    return 0;
}


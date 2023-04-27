#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

struct edge {
    int src, dest, weight;
};

int find(int parent[], int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void union_sets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int compare(const void *a, const void *b) {
    struct edge *edgeA = (struct edge *)a;
    struct edge *edgeB = (struct edge *)b;
    return edgeA->weight - edgeB->weight;
}

void kruskal(struct edge edges[], int num_edges, int num_vertices) {
    int parent[num_vertices], rank[num_vertices], i, num_mst_edges = 0, total_weight = 0;
    for (i = 0; i < num_vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    qsort(edges, num_edges, sizeof(struct edge), compare);
    for (i = 0; i < num_edges && num_mst_edges < num_vertices-1; i++) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);
        if (x != y) {
            union_sets(parent, rank, x, y);
            printf("%d - %d    %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            total_weight += edges[i].weight;
            num_mst_edges++;
        }
    }
    printf("Total weight: %d\n", total_weight);
}

int main() {
    struct edge edges[MAX_EDGES];
    int num_vertices, num_edges, i;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);
    printf("Enter the edges and their weights in the format: <source> <destination> <weight>\n");
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    printf("Minimum spanning tree:\n");
    kruskal(edges, num_edges, num_vertices);
    return 0;
}

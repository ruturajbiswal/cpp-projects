#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES]; 

void dfs(int node, int num_nodes) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, num_nodes);
        }
    }
}

int main() {
    int num_nodes, num_edges, start_node;

    printf("Enter the number of nodes and edges in the graph: ");
    scanf("%d%d", &num_nodes, &num_edges);

    printf("Enter the edges of the graph: \n");
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    printf("Enter the start node: ");
    scanf("%d", &start_node);

    printf("DFS traversal: ");
    dfs(start_node, num_nodes);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES]; 
int visited[MAX_NODES]; 
int queue[MAX_NODES]; 
int front = -1, rear = -1; 

void bfs(int start, int num_nodes) {
    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        int node = queue[++front];
        printf("%d ", node);

        for (int i = 0; i < num_nodes; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
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

    printf("BFS traversal: ");
    bfs(start_node, num_nodes);

    return 0;
}

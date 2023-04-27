#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES]; 
int dist[MAX_NODES];
int visited[MAX_NODES]; 

int find_min_distance(int num_nodes) {
    int min_distance = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i] && dist[i] < min_distance) {
            min_distance = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstra(int start, int num_nodes) {
  
    for (int i = 0; i < num_nodes; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < num_nodes - 1; i++) {
        int u = find_min_distance(num_nodes);
        visited[u] = 1;

        for (int v = 0; v < num_nodes; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int num_nodes, num_edges, start_node;

    printf("Enter the number of nodes and edges in the graph: ");
    scanf("%d%d", &num_nodes, &num_edges);

    printf("Enter the edges of the graph and their weights: \n");
    for (int i = 0; i < num_edges; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        graph[u][v] = graph[v][u] = w;
    }

    printf("Enter the start node: ");
    scanf("%d", &start_node);

    dijkstra(start_node, num_nodes);

    printf("Shortest distances from node %d: \n", start_node);
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %d\n", i, dist[i]);
    }

    return 0;
}

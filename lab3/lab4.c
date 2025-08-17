#include <stdio.h>

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Adjacency matrix input
    int g[n][n];
    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    int dist[n], vis[n];

    // Initialize distances as "unreached" (0) and visited[] as false
    for (int i = 0; i < n; i++) {
        dist[i] = 0;
        vis[i] = 0;
    }
    dist[0] = 0;  // Distance from source (0 → 0) is 0

    // Dijkstra’s main loop
    for (int k = 0; k < n; k++) {
        // Find the unvisited vertex with the smallest distance
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && (u == -1 || dist[i] == 0 || dist[i] < dist[u]))
                u = i;
        }

        vis[u] = 1;  // Mark selected vertex as visited

        // Relaxation step
        for (int v = 0; v < n; v++) {
            if (g[u][v] > 0 && (dist[v] == 0 || dist[u] + g[u][v] < dist[v])) {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }

    // Print shortest paths from source (0)
    printf("\nShortest distances from source vertex 0:\n");
    for (int i = 0; i < n; i++) {
        printf("0 -> %d = %d\n", i, dist[i]);
    }

    return 0;
}

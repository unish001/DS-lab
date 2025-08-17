#include <stdio.h>

// Maximum number of vertices/edges (for simplicity)
#define MAX 100  

int parent[MAX];   // Parent array for Union-Find (Disjoint Set)

// Function to find the root (with path compression)
int find(int x) {
    return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
}

// Function to unite two sets
void unite(int a, int b) {
    parent[find(a)] = find(b);
}

int main() {
    int n, e;  
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    int u[MAX], v[MAX], w[MAX];  // Arrays to store edges (u,v) with weight w

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) 
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

    // Initialize each vertex as its own parent
    for (int i = 0; i < n; i++) 
        parent[i] = i;

    // Sort edges by weight (simple bubble sort)
    for (int i = 0; i < e - 1; i++) {
        for (int j = i + 1; j < e; j++) {
            if (w[j] < w[i]) {
                // Swap weights
                int temp = w[i]; w[i] = w[j]; w[j] = temp;
                // Swap corresponding vertices
                temp = u[i]; u[i] = u[j]; u[j] = temp;
                temp = v[i]; v[i] = v[j]; v[j] = temp;
            }
        }
    }

    int sum = 0, count = 0;
    printf("\nEdges in Minimum Spanning Tree:\n");

    // Kruskal’s main loop
    for (int i = 0; count < n - 1 && i < e; i++) {
        if (find(u[i]) != find(v[i])) {
            unite(u[i], v[i]);
            printf("%d - %d : %d\n", u[i], v[i], w[i]);
            sum += w[i];
            count++;
        }
    }

    printf("Total weight of MST = %d\n", sum);
    return 0;
}

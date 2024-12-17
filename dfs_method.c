#include <stdio.h>

#define MAX 10  // Maximum number of nodes

void dfs(int adj[MAX][MAX], int visited[MAX], int n, int node) {
    visited[node] = 1;  // Mark the current node as visited
    for (int v = 0; v < n; v++) {
        if (adj[node][v] == 1 && !visited[v]) {  // Check for an edge and if `v` is unvisited
            dfs(adj, visited, n, v);  // Recursively visit the neighbor
        }
    }
}

int isConnected(int adj[MAX][MAX], int n) {
    int visited[MAX] = {0};  // Array to track visited nodes
    dfs(adj, visited, n, 0); // Perform DFS starting from node 0

    // Check if all nodes are visited
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return 0;  // If any node is unvisited, the graph is not connected
        }
    }
    return 1;  // All nodes were visited, so the graph is connected
}

int main() {
    int n, adj[MAX][MAX];

    // Input the graph
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Check connectivity
    if (isConnected(adj, n)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
/* Output: 
Enter the number of nodes: 4
Enter the adjacency matrix:
0 1 1 1 
1 0 0 1
1 0 0 1
1 1 1 0
The graph is connected.


=== Code Execution Successful ===

*/

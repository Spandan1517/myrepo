#include <stdio.h>
#define INF 999

int main() {
    int n, i, j, start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int graph[n][n];
    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node (1-%d): ", n);
    scanf("%d", &start);
    start--;

    int dist[n], visited[n];
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;
        for (i = 0; i < n; i++)
            if (!visited[i] && dist[i] <= min)
                min = dist[i], u = i;

        if (u == -1) break;
        visited[u] = 1;

        for (i = 0; i < n; i++)
            if (!visited[i] && graph[u][i] && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
    }

    printf("Shortest distances from node %d:\n", start + 1);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("Node %d: -1 (unreachable)\n", i + 1);
        else
            printf("Node %d: %d\n", i + 1, dist[i]);
    }
    return 0;
}

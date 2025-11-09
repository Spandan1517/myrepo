#include <stdio.h>

#define N 9
int adj[10][10], visited[10];

void bfs(int start) {
    int queue[20], front = 0, rear = 0, i;
    for (i = 1; i <= N; i++) visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS Order: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (i = 1; i <= N; i++) {
            if (adj[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfsUtil(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 1; i <= N; i++) {
        if (adj[v][i] && !visited[i])
            dfsUtil(i);
    }
}

void dfs(int start) {
    for (int i = 1; i <= N; i++) visited[i] = 0;
    printf("DFS Order: ");
    dfsUtil(start);
    printf("\n");
}

int main() {
    for (int i = 1; i <= N; i++) {
        if (i % 3 != 0) { adj[i][i + 1] = adj[i + 1][i] = 1; }
        if (i + 3 <= N) { adj[i][i + 3] = adj[i + 3][i] = 1; }
    }

    printf("Starting at node 1\n");
    bfs(1);
    dfs(1);
    return 0;
}

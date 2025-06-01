#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
		int i;
        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int n = 4;  // Number of nodes
    int start = 0;  // Starting node for BFS

    // Hardcoded adjacency matrix for graph with 4 nodes:
    // Graph:
    // 0 -- 1
    // |    |
    // 2    3
    int graph[MAX][MAX] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 0},
        {0, 1, 0, 0}
    };

    bfs(graph, n, start);

    return 0;
}


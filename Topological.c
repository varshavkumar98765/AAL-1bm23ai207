#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_V 100

int graph[MAX_V][MAX_V];
int visited[MAX_V];
int stack[MAX_V];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

void topologicalSortUtil(int v, int V) {
    int i;
    visited[v] = 1;

    for (i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            topologicalSortUtil(i, V);
        }
    }

    push(v);
}

void topologicalSort(int V) {
    int i;
    for (i = 0; i < V; i++) {
        visited[i] = 0;
    }

    for (i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, V);
        }
    }

    printf("Topological Order: ");
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int V = 8;
    int i, j;

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    // edges = [[2, 3], [3, 1], [4, 0], [4, 1], [5, 0], [5, 2]]
    graph[1][0] = 1;
    graph[0][3] = 1;
    graph[1][3] = 1;
    graph[3][2] = 1;
    graph[6][3] = 1;
    graph[3][4] = 1;
    graph[6][5] = 1;
    graph[5][4] = 1;
    graph[7][5] = 1;
    

    topologicalSort(V);

    return 0;
}


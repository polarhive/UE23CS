#include <stdio.h>
#define MAX 100

typedef struct {
    int vertex;
    int adjMatrix[MAX][MAX];
} GRAPH;

void dfs_adjMat(GRAPH *g, int start, int parent, int visited[MAX]) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 1; i <= g->vertex; i++) {
        if (g->adjMatrix[start][i] == 1) {
            if (!visited[i])
                dfs_adjMat(g, i, start, visited); //recursive call
            else if (i != parent) {//for directed graph
                // Cycle detected
                printf("\nCycle detected: %d -> %d\n", start, i);
            }
        }
    }
}
int hasCycle(GRAPH *g) {//To find are there any cycle choosing each node as source node
    int visited[MAX] = {0};
    for (int i = 1; i <= g->vertex; i++) {
        if (!visited[i]) {
            dfs_adjMat(g, i, -1, visited);
        }
    }
    return 0;
}

int main() {
    GRAPH g = {5, {{0,0,0,0,0,0}, {0,0,1,1,0,0}, {0,1,0,0,1,0}, {0,1,0,0,1,1}, {0,0,1,1,0,0}, {0,0,0,1,0,0}}};
    hasCycle(&g);
    return 0;
}

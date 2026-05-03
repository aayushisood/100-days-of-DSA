#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, minIndex = -1;

    for (int v = 1; v <= n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0;
    parent[1] = -1;

    for (int count = 1; count <= n - 1; count++) {
        int u = minKey(key, mstSet, n);

        mstSet[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;
    for (int i = 2; i <= n; i++) {
        totalWeight += graph[i][parent[i]];
    }

    printf("%d\n", totalWeight);

    return 0;
}

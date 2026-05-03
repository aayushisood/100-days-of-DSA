#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m, u, v, directed;
    scanf("%d %d", &n, &m);

    // 0 = undirected, 1 = directed
    scanf("%d", &directed);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        if (!directed) {
            newNode = createNode(u);
            newNode->next = adj[v];
            adj[v] = newNode;
        }
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}

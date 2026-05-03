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

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void topoDFS(int v, struct Node* adj[], int visited[], int stack[], int *top) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            topoDFS(temp->vertex, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[++(*top)] = v;
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    int visited[n];
    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoDFS(i, adj, visited, stack, &top);
        }
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}

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

void addEdge(struct Node* adj[], int u, int v, int directed) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    if (!directed) {
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }
}

void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, u, v, s, directed;
    scanf("%d %d", &n, &m);

    // 0 = undirected, 1 = directed
    scanf("%d", &directed);

    struct Node* adj[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v, directed);
    }

    scanf("%d", &s);

    dfs(s, adj, visited);

    return 0;
}

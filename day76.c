#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

struct Node* create(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = NULL;
    return node;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = create(v);
    node->next = adj[u];
    adj[u] = node;

    node = create(u);
    node->next = adj[v];
    adj[v] = node;
}

void dfs(int u, struct Node* adj[], int visited[]) {
    visited[u] = 1;

    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->v]) {
            dfs(temp->v, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];
    int visited[n + 1];

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }

    printf("%d\n", components);

    return 0;
}

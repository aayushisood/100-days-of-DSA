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

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

int dfs(int v, int parent, struct Node* adj[], int visited[]) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->vertex;

        if (!visited[u]) {
            if (dfs(u, v, adj, visited))
                return 1;
        }
        else if (u != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }
    return 0;
}

int hasCycle(int n, struct Node* adj[]) {
    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    if (hasCycle(n, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

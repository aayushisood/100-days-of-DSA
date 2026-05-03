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

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    int indegree[n];

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        indegree[v]++;
    }

    // Queue
    int queue[1000];
    int front = 0, rear = 0;

    // Push all vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    // Kahn's Algorithm
    int count = 0;
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        struct Node* temp = adj[curr];
        while (temp) {
            indegree[temp->vertex]--;
            if (indegree[temp->vertex] == 0) {
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    // If not all vertices are processed → cycle exists
    if (count != n) {
        printf("\nCycle exists\n");
    }

    return 0;
}

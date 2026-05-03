#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v, int w, int directed) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    if (!directed) {
        newNode = createNode(u, w);
        newNode->next = adj[v];
        adj[v] = newNode;
    }
}

// Min Heap (Priority Queue)
struct HeapNode {
    int vertex, dist;
};

struct HeapNode heap[MAX];
int size = 0;

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l].dist < heap[smallest])
        smallest = l;
    if (r < size && heap[r].dist < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void push(int v, int d) {
    heap[size].vertex = v;
    heap[size].dist = d;
    heapifyUp(size);
    size++;
}

struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

int isEmpty() {
    return size == 0;
}

// Dijkstra
void dijkstra(struct Node* adj[], int n, int src) {
    int dist[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;
    push(src, 0);

    while (!isEmpty()) {
        struct HeapNode curr = pop();
        int u = curr.vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
}

int main() {
    int n, m, u, v, w, src, directed;

    scanf("%d %d", &n, &m);

    // 0 = undirected, 1 = directed
    scanf("%d", &directed);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w, directed);
    }

    scanf("%d", &src);

    dijkstra(adj, n, src);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue node (for BFS with horizontal distance)
struct QNode {
    struct Node* node;
    int hd;
};

// Create new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order (-1 = NULL)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2*i + 1, r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

// Vertical order traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QNode queue[1000];
    int front = 0, rear = 0;

    int hdMap[2000][100];  // store values for each hd
    int count[2000] = {0};

    int offset = 1000; // to handle negative hd

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int idx = hd + offset;
        hdMap[idx][count[idx]++] = curr->data;

        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, hd - 1};
        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, hd + 1};
    }

    // Print from leftmost to rightmost
    for (int i = 0; i < 2000; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", hdMap[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}

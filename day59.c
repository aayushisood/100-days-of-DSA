#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int postIndex;

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Build tree from inorder + postorder
struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd) {
    if (inStart > inEnd)
        return NULL;

    int curr = postorder[postIndex--];
    struct Node* node = newNode(curr);

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, curr);

    // Important: build right subtree first
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1);

    return node;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    preorder(root);

    return 0;
}

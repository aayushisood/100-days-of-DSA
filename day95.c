#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10

typedef struct Node {
    float val;
    struct Node* next;
} Node;

Node* create(float x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = x;
    n->next = NULL;
    return n;
}

void insert(Node** bucket, float x) {
    Node* newNode = create(x);

    if (*bucket == NULL || (*bucket)->val >= x) {
        newNode->next = *bucket;
        *bucket = newNode;
        return;
    }

    Node* curr = *bucket;
    while (curr->next && curr->next->val < x)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;
}

void printBuckets(Node* bucket[]) {
    for (int i = 0; i < BUCKETS; i++) {
        Node* curr = bucket[i];
        while (curr) {
            printf("%.2f ", curr->val);
            curr = curr->next;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    Node* bucket[BUCKETS];

    for (int i = 0; i < BUCKETS; i++)
        bucket[i] = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);

        int idx = arr[i] * BUCKETS;
        if (idx >= BUCKETS) idx = BUCKETS - 1;

        insert(&bucket[idx], arr[i]);
    }

    printBuckets(bucket);

    return 0;
}

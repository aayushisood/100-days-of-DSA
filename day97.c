#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

// Simple min-heap on end times
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && heap[l] < heap[smallest])
        smallest = l;
    if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void insertHeap(int heap[], int *size, int val) {
    heap[*size] = val;
    heapifyUp(heap, *size);
    (*size)++;
}

void popHeap(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

// compare for sorting by start time
int cmp(const void *a, const void *b) {
    Meeting *x = (Meeting *)a;
    Meeting *y = (Meeting *)b;
    return x->start - y->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // sort by start time
    qsort(arr, n, sizeof(Meeting), cmp);

    int heap[n]; // stores end times
    int size = 0;

    insertHeap(heap, &size, arr[0].end);

    for (int i = 1; i < n; i++) {
        // if earliest ending meeting finished
        if (heap[0] <= arr[i].start) {
            popHeap(heap, &size);
        }

        insertHeap(heap, &size, arr[i].end);
    }

    printf("%d\n", size);

    return 0;
}

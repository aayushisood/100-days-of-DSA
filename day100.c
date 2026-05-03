#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

int *countSmaller;
Pair *temp;

void merge(Pair arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    int rightCount = 0;

    while (i <= m && j <= r) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            countSmaller[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= m) {
        countSmaller[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Pair arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Pair arr[n];
    countSmaller = (int*)calloc(n, sizeof(int));
    temp = (Pair*)malloc(n * sizeof(Pair));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", countSmaller[i]);
    }

    return 0;
}

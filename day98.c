#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;
    return x->start - y->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Sort by start time
    qsort(arr, n, sizeof(Interval), cmp);

    Interval merged[n];
    int idx = 0;

    merged[0] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= merged[idx].end) {
            // overlap → merge
            if (arr[i].end > merged[idx].end)
                merged[idx].end = arr[i].end;
        } else {
            // no overlap
            idx++;
            merged[idx] = arr[i];
        }
    }

    for (int i = 0; i <= idx; i++) {
        printf("%d %d\n", merged[i].start, merged[i].end);
    }

    return 0;
}

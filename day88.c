#include <stdio.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
    }

    return count >= k;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // sort stalls
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (stalls[j] > stalls[j + 1]) {
                int temp = stalls[j];
                stalls[j] = stalls[j + 1];
                stalls[j + 1] = temp;
            }
        }
    }

    int low = 1, high = stalls[n - 1] - stalls[0], ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}

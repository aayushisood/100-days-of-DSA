#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int sum(int arr[], int start, int end) {
    int s = 0;
    for (int i = start; i <= end; i++)
        s += arr[i];
    return s;
}

// Check if we can allocate with maxPages limit
int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (currentSum + arr[i] > maxPages) {
            students++;
            currentSum = arr[i];

            if (students > m)
                return 0;
        } else {
            currentSum += arr[i];
        }
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int total = 0, maxBook = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        total += arr[i];
        if (arr[i] > maxBook)
            maxBook = arr[i];
    }

    int low = maxBook, high = total, ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}

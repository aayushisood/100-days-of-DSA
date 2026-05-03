#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Check if k painters can paint within maxTime
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (currSum + boards[i] > maxTime) {
            painters++;
            currSum = boards[i];

            if (painters > k)
                return 0;
        } else {
            currSum += boards[i];
        }
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int total = 0, maxBoard = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        total += boards[i];
        if (boards[i] > maxBoard)
            maxBoard = boards[i];
    }

    int low = maxBoard, high = total, ans = total;

    // Binary search on answer
    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}

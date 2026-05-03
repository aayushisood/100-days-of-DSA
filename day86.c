#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long low = 0, high = n, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long sq = mid * mid;

        if (sq == n) {
            ans = mid;
            break;
        } else if (sq < n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}

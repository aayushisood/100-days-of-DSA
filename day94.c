#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    int max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }

    // Frequency array
    int *freq = (int*)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    // Prefix sum
    for (int i = 1; i <= max; i++)
        freq[i] += freq[i - 1];

    // Output array
    int output[n];

    // Stable counting sort (iterate backwards)
    for (int i = n - 1; i >= 0; i--) {
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", output[i]);

    free(freq);

    return 0;
}

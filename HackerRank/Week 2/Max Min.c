#include <stdio.h>
#include <stdlib.h>

int cmpInt(const void *a, const void *b) {
    long x = *(long *)a;
    long y = *(long *)b;
    return (x > y) - (x < y);
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }

    // Sort array
    qsort(arr, n, sizeof(long), cmpInt);

    // Find minimum unfairness
    long minDiff = arr[k-1] - arr[0];
    for (int i = 1; i <= n - k; i++) {
        long diff = arr[i + k - 1] - arr[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    printf("%ld\n", minDiff);
    return 0;
}
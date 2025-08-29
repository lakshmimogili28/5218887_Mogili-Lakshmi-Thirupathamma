#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Using long long to handle big numbers safely
    long long *arr = (long long*)calloc(n + 2, sizeof(long long));
    if (!arr) return 1;

    // Read operations
    for (int i = 0; i < m; i++) {
        int a, b;
        long long k;
        scanf("%d %d %lld", &a, &b, &k);

        // Difference array trick
        arr[a] += k;
        arr[b + 1] -= k;
    }

    // Build prefix sum and track maximum
    long long max = 0, current = 0;
    for (int i = 1; i <= n; i++) {
        current += arr[i];
        if (current > max) max = current;
    }

    printf("%lld\n", max);

    free(arr);
    return 0;
}

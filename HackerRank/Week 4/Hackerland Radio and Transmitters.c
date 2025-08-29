#include <stdio.h>
#include <stdlib.h>

/* Compare function for qsort */
static int cmp_ll(const void *a, const void *b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(void) {
    int n;
    long long k;
    if (scanf("%d %lld", &n, &k) != 2) return 0;

    long long *a = (long long*)malloc(sizeof(long long) * n);
    if (!a) return 0;

    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

    qsort(a, n, sizeof(long long), cmp_ll);

    int i = 0;
    int transmitters = 0;

    while (i < n) {
        // Step 1: start from the leftmost uncovered house
        long long left = a[i] + k;

        // Move i to the rightmost house within k of a[i]
        while (i < n && a[i] <= left) i++;

        // Place transmitter at the furthest such house (i-1)
        int pos = i - 1;
        transmitters++;

        // Step 2: cover houses to the right within k of the transmitter
        long long cover = a[pos] + k;
        while (i < n && a[i] <= cover) i++;
    }

    printf("%d\n", transmitters);

    free(a);
    return 0;
}

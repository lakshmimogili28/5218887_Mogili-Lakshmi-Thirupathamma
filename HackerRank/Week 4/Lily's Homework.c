#include <stdio.h>
#include <stdlib.h>

// Structure to hold value + original index
typedef struct {
    int value;
    int index;
} Pair;

// Compare function for ascending
int cmpAsc(const void *a, const void *b) {
    return ((Pair*)a)->value - ((Pair*)b)->value;
}

// Compare function for descending
int cmpDesc(const void *a, const void *b) {
    return ((Pair*)b)->value - ((Pair*)a)->value;
}

// Function to count swaps needed to transform array into sorted form
int countSwaps(int *arr, int n, int descending) {
    Pair *pairs = (Pair*)malloc(n * sizeof(Pair));
    if (!pairs) return 0;

    // Fill with value + original index
    for (int i = 0; i < n; i++) {
        pairs[i].value = arr[i];
        pairs[i].index = i;
    }

    // Sort pairs
    if (descending) {
        qsort(pairs, n, sizeof(Pair), cmpDesc);
    } else {
        qsort(pairs, n, sizeof(Pair), cmpAsc);
    }

    // Visited array to mark if element is already in correct place
    int *visited = (int*)calloc(n, sizeof(int));
    if (!visited) return 0;

    int swaps = 0;

    // Process cycles
    for (int i = 0; i < n; i++) {
        // If already visited or already in right place
        if (visited[i] || pairs[i].index == i) continue;

        // Count cycle length
        int cycleSize = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = 1;
            j = pairs[j].index;
            cycleSize++;
        }
        // Swaps needed for cycle = cycleSize - 1
        if (cycleSize > 0) swaps += (cycleSize - 1);
    }

    free(pairs);
    free(visited);
    return swaps;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) return 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ascSwaps = countSwaps(arr, n, 0);
    int descSwaps = countSwaps(arr, n, 1);

    int result = (ascSwaps < descSwaps) ? ascSwaps : descSwaps;
    printf("%d\n", result);

    free(arr);
    return 0;
}

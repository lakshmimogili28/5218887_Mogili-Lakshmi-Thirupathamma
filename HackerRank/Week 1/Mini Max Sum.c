#include <stdio.h>

void miniMaxSum(int arr[], int size) {
    long long total = 0;
    int min = arr[0], max = arr[0];

    for (int i = 0; i < size; i++) {
        total += arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    long long minSum = total - max;
    long long maxSum = total - min;

    printf("%lld %lld\n", minSum, maxSum);
}

int main() {
    int arr[5];

    // Read 5 space-separated integers
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    miniMaxSum(arr, 5);

    return 0;
}
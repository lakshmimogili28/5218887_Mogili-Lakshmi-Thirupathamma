#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void maxSubarray(int arr[], int n) {
    int max_ending_here = arr[0];
    int max_so_far = arr[0];

    int subseq_sum = (arr[0] > 0) ? arr[0] : 0;
    int max_element = arr[0];

    for(int i = 1; i < n; i++) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);

        if(arr[i] > 0)
            subseq_sum += arr[i];

        if(arr[i] > max_element)
            max_element = arr[i];
    }

    if(subseq_sum == 0)
        subseq_sum = max_element;

    printf("%d %d\n", max_so_far, subseq_sum);
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int arr[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        maxSubarray(arr, n);
    }

    return 0;
}
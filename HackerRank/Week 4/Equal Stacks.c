#include <stdio.h>

// function to calculate total height of stack
int totalHeight(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

// main equalStacks function
int equalStacks(int h1[], int n1, int h2[], int n2, int h3[], int n3) {
    int sum1 = totalHeight(h1, n1);
    int sum2 = totalHeight(h2, n2);
    int sum3 = totalHeight(h3, n3);

    // indices to track top of each stack
    int i1 = 0, i2 = 0, i3 = 0;

    // keep removing until equal or any stack becomes empty
    while(!(sum1 == sum2 && sum2 == sum3)) {
        // find max height stack and remove top
        if(sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[i1++];
        }
        else if(sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[i2++];
        }
        else {
            sum3 -= h3[i3++];
        }

        // if any stack is finished, answer is 0
        if(i1 == n1 || i2 == n2 || i3 == n3)
            return 0;
    }

    return sum1; // all are equal now
}

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int h1[n1], h2[n2], h3[n3];

    for(int i = 0; i < n1; i++) scanf("%d", &h1[i]);
    for(int i = 0; i < n2; i++) scanf("%d", &h2[i]);
    for(int i = 0; i < n3; i++) scanf("%d", &h3[i]);

    int ans = equalStacks(h1, n1, h2, n2, h3, n3);
    printf("%d\n", ans);

    return 0;
}
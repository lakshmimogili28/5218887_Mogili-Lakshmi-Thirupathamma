#include <stdio.h>
int main() {
    int n, i;
    int result = 0;

    scanf("%d", &n);  // Read the number of elements

    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        result ^= a[i];  // XOR to find the unique element
    }

    printf("%d\n", result);  // Print only the unique element

    return 0;
}
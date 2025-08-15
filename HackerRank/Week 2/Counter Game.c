#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool isPowerOfTwo(unsigned long long n) {
    return (n && !(n & (n - 1)));
}
unsigned long long largestPowerOfTwo(unsigned long long n) {
    unsigned long long p = 1;
    while (p << 1 <= n) {
        p <<= 1;
    }
    return p;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        unsigned long long n;
        scanf("%llu", &n);

        int turns = 0; 
        while (n > 1) {
            if (isPowerOfTwo(n)) {
                n >>= 1; 
            } else {
                n -= largestPowerOfTwo(n);
            }
            turns++;
        }
        if (turns % 2 == 1) {
            printf("Louise\n");
        } else {
            printf("Richard\n");
        }
    }
    return 0;
}
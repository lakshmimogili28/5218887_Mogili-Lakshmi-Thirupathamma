#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000     

// Generate first q primes using sieve
void generatePrimes(int primes[], int q) {
    int limit = 1300000; // enough to cover first 1200 primes
    static char isPrime[1300000];  // static array, safe in HackerRank

    for (int i = 0; i < limit; i++) isPrime[i] = 1;

    isPrime[0] = isPrime[1] = 0;
    int count = 0;
    for (int i = 2; i < limit && count < q; i++) {
        if (isPrime[i]) {
            primes[count++] = i;
            for (long long j = (long long)i * i; j < limit; j += i)
                isPrime[j] = 0;
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int A[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int primes[1300];
    generatePrimes(primes, q);

    for (int i = 0; i < q; i++) {
        int B[MAXN], bTop = 0;
        int newA[MAXN], aTop = 0;

        for (int j = n - 1; j >= 0; j--) {
            if (A[j] % primes[i] == 0) {
                B[bTop++] = A[j];
            } else {
                newA[aTop++] = A[j];
            }
        }

        for (int k = bTop - 1; k >= 0; k--) {
            printf("%d\n", B[k]);
        }

        n = aTop;
        for (int k = 0; k < aTop; k++) {
            A[k] = newA[k];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", A[i]);
    }

    return 0;
}
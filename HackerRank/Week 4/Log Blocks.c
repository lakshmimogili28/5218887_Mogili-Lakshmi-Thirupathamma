#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAX 1000

// Fast modular exponentiation
long long modpow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);

    // Precompute row configurations
    static long long row[MAX+1];  
    row[0] = 1;  // empty wall
    for (int m = 1; m <= MAX; m++) {
        row[m] = 0;
        for (int brick = 1; brick <= 4; brick++) {
            if (m - brick >= 0)
                row[m] = (row[m] + row[m - brick]) % MOD;
        }
    }

    // For each test case
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        // total ways ignoring cracks
        static long long total[MAX+1], solid[MAX+1];
        for (int i = 1; i <= m; i++) {
            total[i] = modpow(row[i], n);
        }

        // remove invalid (with vertical splits)
        for (int i = 1; i <= m; i++) {
            solid[i] = total[i];
            for (int j = 1; j < i; j++) {
                solid[i] = (solid[i] - (solid[j] * total[i-j]) % MOD + MOD) % MOD;
            }
        }

        printf("%lld\n", solid[m]);
    }
    return 0;
}
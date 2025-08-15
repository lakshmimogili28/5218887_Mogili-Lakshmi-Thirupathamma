#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 100
int cmp_char(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}
const char* gridChallenge(char grid[MAXN][MAXN + 1], int n) {
    for (int i = 0; i < n; i++) {
        qsort(grid[i], n, sizeof(char), cmp_char);
    }
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n - 1; row++) {
            if (grid[row][col] > grid[row + 1][col]) {
                return "NO";
            }
        }
    }
    return "YES";
}

int main() {
    int t, n;
    char grid[MAXN][MAXN + 1];

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
        }
        printf("%s\n", gridChallenge(grid, n));
    }

    return 0;
}
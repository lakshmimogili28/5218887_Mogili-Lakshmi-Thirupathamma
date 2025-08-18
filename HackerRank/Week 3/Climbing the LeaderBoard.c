#include <stdio.h>
#include <stdlib.h>
void climbingLeaderboard(int ranked[], int n, int player[], int m, int result[]) {
    int unique[n], u = 0;
    unique[u++] = ranked[0];
    for (int i = 1; i < n; i++) {
        if (ranked[i] != ranked[i-1]) {
            unique[u++] = ranked[i];
        }
    }
    int idx = u - 1; 
    for (int j = 0; j < m; j++) {
        int score = player[j];
        while (idx >= 0 && score >= unique[idx]) {
            idx--;
        }
        result[j] = (idx < 0) ? 1 : (idx + 2);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int ranked[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ranked[i]);
    }

    int m;
    scanf("%d", &m);

    int player[m], result[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &player[i]);
    }

    climbingLeaderboard(ranked, n, player, m, result);
    for (int i = 0; i < m; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
#include <stdio.h>

void icecreamParlor(int m, int n, int cost[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i] + cost[j] == m) {
                // Printing 1-based indices
                printf("%d %d\n", i + 1, j + 1);
                return;
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);   // number of trips
    
    while (t--) {
        int m, n;
        scanf("%d", &m);  // total money
        scanf("%d", &n);  // number of flavors
        
        int cost[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &cost[i]);
        }
        
        icecreamParlor(m, n, cost);
    }
    
    return 0;
}
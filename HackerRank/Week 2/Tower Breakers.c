#include <stdio.h>


int towerBreakers(int towers, int height) {
    
    if (height == 1) {
        return 2;
    }
    if (towers % 2 == 0) {
        return 2;
    }
    return 1;
}

int main() {
    int t; 
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int winner = towerBreakers(n, m);
        printf("%d\n", winner);
    }

    return 0;
}
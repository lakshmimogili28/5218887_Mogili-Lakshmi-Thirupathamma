#include <stdio.h>
#include <string.h>

#define MAXR 205
#define MAXC 205

static int R, C;
static long long N;              // up to 1e9

static char G0[MAXR][MAXC];      // initial
static char G1[MAXR][MAXC];      // t = 3 pattern
static char G2[MAXR][MAXC];      // t = 5 pattern

static void fill_full(char g[][MAXC]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) g[i][j] = 'O';
        g[i][C] = '\0';          // important for puts/printf("%s")
    }
}

static void explode(char out[][MAXC], char base[][MAXC]) {
    fill_full(out);              // start full, then clear cells hit by bombs
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (base[i][j] == 'O') {
                out[i][j] = '.';
                if (i > 0)     out[i-1][j] = '.';
                if (i < R-1)   out[i+1][j] = '.';
                if (j > 0)     out[i][j-1] = '.';
                if (j < C-1)   out[i][j+1] = '.';
            }
        }
    }
}

static void print_grid(char g[][MAXC]) {
    for (int i = 0; i < R; i++) puts(g[i]);
}

int main(void) {
    if (scanf("%d %d %lld", &R, &C, &N) != 3) return 0;

    for (int i = 0; i < R; i++) {
        scanf("%s", G0[i]);
        G0[i][C] = '\0';         // ensure safe row termination
    }

    if (N == 1) {                // initial state
        print_grid(G0);
        return 0;
    }

    if (N % 2 == 0) {            // every even second: full of bombs
        fill_full(G1);
        print_grid(G1);
        return 0;
    }

    // odd N >= 3: pattern repeats with period 4
    explode(G1, G0);             // t = 3 (and 7, 11, ...)
    explode(G2, G1);             // t = 5 (and 9, 13, ...)

    if (N % 4 == 3) print_grid(G1);
    else            print_grid(G2);

    return 0;
}
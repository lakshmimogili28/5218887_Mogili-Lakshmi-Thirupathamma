#include <stdio.h>
int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int isLeap(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}
void nextDate(int *d, int *m, int *y) {
    int dim = days_in_month[*m - 1];
    if (*m == 2 && isLeap(*y)) dim = 29; 

    (*d)++;
    if (*d > dim) {
        *d = 1;
        (*m)++;
        if (*m > 12) {
            *m = 1;
            (*y)++;
        }
    }
}
long makeNumber(int d, int m, int y) {
    return d * 1000000L + m * 10000L + y;
}
int main() {
    int d1, m1, y1, d2, m2, y2;
    scanf("%d-%d-%d", &d1, &m1, &y1);
    scanf("%d-%d-%d", &d2, &m2, &y2);

    int count = 0;

    while (1) {
        long num = makeNumber(d1, m1, y1);
        if (num % 4 == 0 || num % 7 == 0) count++;

        if (d1 == d2 && m1 == m2 && y1 == y2) break;

        nextDate(&d1, &m1, &y1);
    }

    printf("%d\n", count);
    return 0;
}
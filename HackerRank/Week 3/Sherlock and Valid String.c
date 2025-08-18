#include <stdio.h>
#include <string.h>

#define MAX 26 
const char* isValid(char* s) {
    int freq[MAX] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    int f[MAX], fcount = 0;
    for (int i = 0; i < MAX; i++) {
        if (freq[i] > 0) {
            f[fcount++] = freq[i];
        }
    }
    int min = f[0], max = f[0];
    for (int i = 1; i < fcount; i++) {
        if (f[i] < min) min = f[i];
        if (f[i] > max) max = f[i];
    }
    if (min == max) return "YES";
    int minCount = 0, maxCount = 0;
    for (int i = 0; i < fcount; i++) {
        if (f[i] == min) minCount++;
        if (f[i] == max) maxCount++;
    }
    if (min == 1 && minCount == 1 && (maxCount + minCount == fcount)) {
        return "YES";
    }
    if ((max - min == 1) && maxCount == 1) {
        return "YES";
    }

    return "NO";
}

int main() {
    char s[100005];
    scanf("%s", s);

    printf("%s\n", isValid(s));
    return 0;
}
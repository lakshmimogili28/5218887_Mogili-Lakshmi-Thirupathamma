#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarCipher(char text[], int shift) {
    shift = shift % 26; // keep shift within range

    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base + shift) % 26 + base;
        }
        text[i] = ch;
    }
}

int main() {
    int n, k;
    char str[105]; // a bit bigger than max length

    scanf("%d", &n);
    scanf("%s", str);
    scanf("%d", &k);

    caesarCipher(str, k);
    printf("%s\n", str);

    return 0;
}

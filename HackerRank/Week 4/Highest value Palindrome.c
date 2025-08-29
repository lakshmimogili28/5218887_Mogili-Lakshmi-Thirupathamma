#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char s[n + 1];
    scanf("%s", s);

    int *changed = (int*)calloc(n, sizeof(int)); // track which positions we changed
    if (!changed) return 1;

    int left = 0, right = n - 1;

    // Step 1: Make it a palindrome
    while (left < right) {
        if (s[left] != s[right]) {
            // Replace the smaller digit
            if (s[left] > s[right]) {
                s[right] = s[left];
            } else {
                s[left] = s[right];
            }
            changed[left] = changed[right] = 1; // mark as changed
            k--; // used one change
        }
        left++;
        right--;
    }

    if (k < 0) {
        printf("-1\n"); // Not possible
        free(changed);
        return 0;
    }

    // Step 2: Maximize palindrome value
    left = 0;
    right = n - 1;
    while (left <= right) {
        if (left == right) {
            // Middle digit case (odd length)
            if (k > 0 && s[left] != '9') {
                s[left] = '9';
                k--;
            }
        } else {
            if (s[left] != '9') {
                // Two situations:
                if (changed[left] || changed[right]) {
                    // Already changed once, so making it 9 costs only 1 more
                    if (k > 0) {
                        s[left] = s[right] = '9';
                        k--;
                    }
                } else {
                    // Not changed before, needs 2 moves
                    if (k > 1) {
                        s[left] = s[right] = '9';
                        k -= 2;
                    }
                }
            }
        }
        left++;
        right--;
    }

    printf("%s\n", s);

    free(changed);
    return 0;
}

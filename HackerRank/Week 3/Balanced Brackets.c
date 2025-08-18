#include <stdio.h>
#include <string.h>

#define MAX 1000   // max length of a bracket string

// Function to check if a character is an opening bracket
int isOpening(char c) {
    return (c == '(' || c == '{' || c == '[');
}

// Function to check if brackets match
int isMatching(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

// Function to check if string is balanced
const char* isBalanced(char *s) {
    char stack[MAX];
    int top = -1;   // stack pointer

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (isOpening(c)) {
            // push onto stack
            stack[++top] = c;
        } else {
            // if closing bracket and stack empty -> unbalanced
            if (top == -1) return "NO";

            // check match with top element
            if (!isMatching(stack[top], c)) {
                return "NO";
            }

            // pop from stack
            top--;
        }
    }

    // if stack empty -> balanced
    return (top == -1) ? "YES" : "NO";
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char s[MAX + 1];
        scanf("%s", s);
        printf("%s\n", isBalanced(s));
    }

    return 0;
}
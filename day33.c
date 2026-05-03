#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Check precedence
int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {

        // If operand → add to postfix
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // If '(' → push
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        // If ')' → pop till '('
        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }

        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s\n", postfix);

    return 0;
}

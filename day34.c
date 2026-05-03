#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluate(char* expr) {
    char* token = strtok(expr, " ");

    while (token != NULL) {

        // If operand
        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        }
        else {
            int val1 = pop();
            int val2 = pop();

            switch (token[0]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char expr[100];

    // Read full line including spaces
    fgets(expr, sizeof(expr), stdin);

    // Remove newline
    expr[strcspn(expr, "\n")] = '\0';

    int result = evaluate(expr);

    printf("%d\n", result);

    return 0;
}

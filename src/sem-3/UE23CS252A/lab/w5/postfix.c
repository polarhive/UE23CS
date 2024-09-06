#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 30

// Stack structure
typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int val) {
    if (isFull(s)) {
        printf("Stack is full\n");
    } else {
        s->data[++(s->top)] = val;
    }
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->data[(s->top)--];
    }
}

// Function to evaluate a postfix expression
int eval(char *postfix) {
    Stack s;
    init(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        // If the character is a digit, push it to the stack
        if (isdigit(postfix[i])) {
            push(&s, postfix[i] - '0'); // Convert char to int by subtracting '0'
        }
        // If the character is an operator, pop two elements and apply the operator
        else {
            int val2 = pop(&s);
            int val1 = pop(&s);
            
            switch (postfix[i]) {
                case '+':
                    push(&s, val1 + val2);
                    break;
                case '-':
                    push(&s, val1 - val2);
                    break;
                case '*':
                    push(&s, val1 * val2);
                    break;
                case '/':
                    if (val2 != 0) {
                        push(&s, val1 / val2);
                    } else {
                        printf("Division by zero is undefined\n");
                        return -1;
                    }
                    break;
            }
        }
    }
    
    return pop(&s);
}

void disp(char *postfix) {
    int result = eval(postfix);
    printf("%d\n", result);
}

int main() {
    char postfix[MAX];
    scanf("%s", postfix);  // Input the postfix expression
    disp(postfix);         // Display the evaluated result
    return 0;
}

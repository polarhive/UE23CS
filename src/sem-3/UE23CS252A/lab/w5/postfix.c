#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 30

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

void push(Stack *s, int val) {
    if (isFull(s)) {
        printf("Stack is full\n");
    } else {
        s->data[++(s->top)] = val;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->data[(s->top)--];
    }
}

int eval(char *postfix) {
    Stack s;
    init(&s);
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            // Convert the single digit character to its corresponding integer value
            push(&s, postfix[i] - '0');
        } else {
            // Pop two operands for the operator
            int val2 = pop(&s);
            if (val2 == -1) return -1;  // Stack was empty during pop
            int val1 = pop(&s);
            if (val1 == -1) return -1;  // Stack was empty during pop

            // Perform the operation based on the operator
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
        i++;
    }

    // Final result should be the last item in the stack
    return pop(&s);
}

void disp(char *postfix) {
    int result = eval(postfix);
    if (result != -1) {
        printf("%d\n", result);
    }
}

int main() {
    char postfix[MAX];
    scanf("%s", postfix);  // Input the postfix expression
    disp(postfix);         // Display the evaluated result
    return 0;
}

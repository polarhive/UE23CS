#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
} Stack;

void initStack(Stack *stack, int size) {
    stack->data = (int*)malloc(size * sizeof(int));
    stack->top = -1;
}

void push(Stack *stack, int value) {
    stack->data[++(stack->top)] = value;
}

int pop(Stack *stack) {
    return stack->data[(stack->top)--];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int top(Stack *stack) {
    return stack->data[stack->top];
}

// Find the next greater element for each element in sensorReadings1
void nextGreaterReading(int *sensorReadings1, int n1, int *sensorReadings2, int n2) {
    Stack stack;
    initStack(&stack, n2);

    int *nextGreater = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++) {
        nextGreater[i] = -1; // Initialize to -1
    }

    for (int i = n2 - 1; i >= 0; i--) {
        while (!isEmpty(&stack) && top(&stack) <= sensorReadings2[i]) {
            pop(&stack);
        }

        if (!isEmpty(&stack)) {
            nextGreater[i] = top(&stack);
        }

        push(&stack, sensorReadings2[i]);
    }

    printf("[");
    for (int i = 0; i < n1; i++) {
        int found = 0;
        for (int j = 0; j < n2; j++) {
            if (sensorReadings2[j] == sensorReadings1[i]) {
                printf("%d", nextGreater[j]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("-1");
        }
        if (i < n1 - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(stack.data);
    free(nextGreater);
}

int main() {
    int n1, n2;

    scanf("%d", &n1);
    int *sensorReadings1 = (int*)malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        scanf("%d", &sensorReadings1[i]);
    }

    scanf("%d", &n2);
    int *sensorReadings2 = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++) {
        scanf("%d", &sensorReadings2[i]);
    }

    nextGreaterReading(sensorReadings1, n1, sensorReadings2, n2);
    free(sensorReadings1);
    free(sensorReadings2);

    return 0;
}

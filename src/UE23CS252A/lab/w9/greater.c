#include <stdio.h>
#include <stdlib.h>

// Function to find the next greater reading for each reading in sensorReadings1
int* nextGreaterElement(int* sensorReadings1, int sensorReadings1Size, int* sensorReadings2, int sensorReadings2Size, int* returnSize) {
    // the next greater element for each reading in sensorReadings2
    int* nextGreaterMap = (int*)malloc(sensorReadings2Size * sizeof(int));
    for (int i = 0; i < sensorReadings2Size; i++) {
        nextGreaterMap[i] = -1;  // all are -1
    }

    // keep track of readings for which we need to find the next greater element
    int* stack = (int*)malloc(sensorReadings2Size * sizeof(int));
    int top = -1;  // Stack pointer (empty stack initially)

    // traverse sensorReadings2 and fill using stack
    for (int i = 0; i < sensorReadings2Size; i++) {
        while (top >= 0 && sensorReadings2[i] > sensorReadings2[stack[top]]) {
            nextGreaterMap[stack[top]] = sensorReadings2[i];
            top--;
        }
        stack[++top] = i;
    }

    int* result = (int*)malloc(sensorReadings1Size * sizeof(int));
    *returnSize = sensorReadings1Size;

    // find the next greater reading in sensorReadings2
    for (int i = 0; i < sensorReadings1Size; i++) {
        int j;
        for (j = 0; j < sensorReadings2Size; j++) {
            if (sensorReadings2[j] == sensorReadings1[i]) {
                result[i] = nextGreaterMap[j];
                break;
            }
        }
    }

    free(stack);        // free memory
    free(nextGreaterMap); // free memory
    return result;
}

int main() {
    int n1, n2;
    
    scanf("%d", &n1);
    int* sensorReadings1 = (int*)malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        scanf("%d", &sensorReadings1[i]);
    }

    scanf("%d", &n2);
    int* sensorReadings2 = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++) {
        scanf("%d", &sensorReadings2[i]);
    }

    int returnSize;
    int* result = nextGreaterElement(sensorReadings1, n1, sensorReadings2, n2, &returnSize);

    // Print the result as an array
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(sensorReadings1);
    free(sensorReadings2);
    free(result);
    return 0;
}

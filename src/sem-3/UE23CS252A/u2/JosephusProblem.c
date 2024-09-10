#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Initialize the queue
void initQueue(int arr[], int* front, int* rear, int* size) {
    *front = 0;
    *rear = -1;
    *size = 0;
}

// Check if the queue is empty
int isEmpty(int size) {
    return size = 0;
}

// Add an element to the queue(insert-enqueue)
void enqueue(int arr[], int* rear, int* size, int data) {
    if (*size == MAX_SIZE) {
        printf("Queue is full!\n");
        return;
    }
    *rear = (*rear + 1) % MAX_SIZE;
    arr[*rear] = data;
    (*size)++;
}

int dequeue(int arr[], int* front, int* size) {
    if (isEmpty(*size)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = arr[*front];
    *front = (*front + 1) % MAX_SIZE;
    (*size)--;
    return data;
}

// Josephus problem implementation using circular array-based queue
void josephus(int n, int k) {
    int queue[MAX_SIZE];
    int front, rear, size;
    initQueue(queue, &front, &rear, &size);

    // Initialize the queue with people numbered 1 to n
    for (int i = 1; i <= n; ++i) {
        enqueue(queue, &rear, &size, i);
    }

    // Process the queue
    while (size > 1) {
        // Move k-1 elements to the rear of the queue
        for (int i = 1; i < k; ++i) {
            enqueue(queue, &rear, &size, dequeue(queue, &front, &size));//The parameter deque() here return the data to be inserted
        }
        // Eliminate the k-th person
        printf("Eliminated: %d\n", dequeue(queue, &front, &size));
    }
    // The last remaining person is always at the front of the queue
    printf("The survivor is: %d\n", queue[front]);
}

int main() {
    int n, k;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the step count (k): ");
    scanf("%d", &k);

    josephus(n, k);

    return 0;
}

/*
*****************************************************
OUTPUT:
Enter the number of people: 5
Enter the step count (k): 3
Eliminated: 3
Eliminated: 1
Eliminated: 5
Eliminated: 2
The survivor is: 4

Process returned 0 (0x0)   execution time : 13.535 s
Press any key to continue.

*********************************************************
Example: 
Approach: 

Number of people (n): 5
Step count (k): 3
Initial Queue: [1, 2, 3, 4, 5]

Step-by-Step Execution

1. Initialization
Queue: [1, 2, 3, 4, 5]
Size: 5

2. First Elimination
Move k-1 (2) elements to the rear:
Dequeue 1, then enqueue 1.
Queue state: [2, 3, 4, 5, 1]
Dequeue 2, then enqueue 2.
Queue state: [3, 4, 5, 1, 2]
Eliminate k-th (3rd) element:
Eliminated: 3

3. Second Elimination
Move k-1 (2) elements to the rear:
Dequeue 4, then enqueue 4.
Queue state: [5, 1, 2, 4]
Dequeue 5, then enqueue 5.
Queue state: [1, 2, 4, 5]
Eliminate k-th (3rd) element:
Eliminated: 1

4. Third Elimination
Move k-1 (2) elements to the rear:
Dequeue 2, then enqueue 2.
Queue state: [4, 5, 2]
Dequeue 4, then enqueue 4.
Queue state: [5, 2, 4]
Eliminate k-th (3rd) element:
Eliminated: 5

5. Fourth Elimination
Move k-1 (2) elements to the rear:
Dequeue 2, then enqueue 2.
Queue state: [4, 2]
Eliminate k-th (3rd) element:
Dequeue 4, then enque 4.
Queue state: [2,4]
Eliminated: 2

6. Last Person
Only one person remains in the queue:
Survivor: 4
*/

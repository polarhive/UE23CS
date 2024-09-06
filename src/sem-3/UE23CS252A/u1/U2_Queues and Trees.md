Queues & Dequeue: Basic Structure of a 
- Simple Queue
- Circular Queue
- Priority Queue
## Priority Queue

Give a space at the front-end of the queue.

- array
- linked list
- heaps

In the context of data structures, a **Priority Queue** is an abstract data type that operates similarly to a regular queue, but with an added feature: each element has a **priority** assigned to it. When elements are dequeued, the element with the highest priority is dequeued first, rather than strictly following the "first-in, first-out" (FIFO) rule of simple queues.

### Key Points:

1. **Simple Queue**: Elements are inserted at the rear and removed from the front. It follows the FIFO principle.
2. **Circular Queue**: Like a simple queue but treats the queue as circular, meaning the rear wraps around to the front when it reaches the end of the queue.
3. **Priority Queue**: Elements are dequeued based on priority. Elements with the highest priority are dequeued first, and if two elements have the same priority, they are dequeued in the order they were enqueued.

### Priority Queue - in C

The following C code demonstrates a simple implementation of a priority queue using arrays, where we insert elements with a priority and dequeue the element with the highest priority first.

```c
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a priority queue node
struct Node {
    int data;
    int priority;
};

// Structure to represent a priority queue
struct PriorityQueue {
    struct Node* nodes;
    int size;
    int capacity;
};

// Function to create a priority queue
struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->nodes = (struct Node*)malloc(capacity * sizeof(struct Node));
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// Function to enqueue an element with a priority
void enqueue(struct PriorityQueue* queue, int data, int priority) {
    if (queue->size == queue->capacity) {
        printf("Queue is full!\n");
        return;
    }

    // Insert the new element at the rear
    queue->nodes[queue->size].data = data;
    queue->nodes[queue->size].priority = priority;
    queue->size++;
}

// Function to find the element with the highest priority
int findHighestPriority(struct PriorityQueue* queue) {
    int maxIndex = 0;
    for (int i = 1; i < queue->size; i++) {
        if (queue->nodes[i].priority > queue->nodes[maxIndex].priority) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to dequeue the highest priority element
void dequeue(struct PriorityQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    // Find the element with the highest priority
    int maxIndex = findHighestPriority(queue);
    printf("Dequeued element: %d with priority %d\n", queue->nodes[maxIndex].data, queue->nodes[maxIndex].priority);

    // Remove the element by shifting the rest
    for (int i = maxIndex; i < queue->size - 1; i++) {
        queue->nodes[i] = queue->nodes[i + 1];
    }
    queue->size--;
}

// Function to display the queue elements and their priorities
void displayQueue(struct PriorityQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Priority Queue: \n");
    for (int i = 0; i < queue->size; i++) {
        printf("Element: %d, Priority: %d\n", queue->nodes[i].data, queue->nodes[i].priority);
    }
}

int main() {
    int capacity = 5;
    struct PriorityQueue* queue = createPriorityQueue(capacity);

    // Enqueue elements with different priorities
    enqueue(queue, 10, 2);
    enqueue(queue, 30, 3);
    enqueue(queue, 20, 1);
    enqueue(queue, 40, 5);

    // Display the queue
    displayQueue(queue);

    // Dequeue elements based on priority
    dequeue(queue);
    displayQueue(queue);

    dequeue(queue);
    displayQueue(queue);

    return 0;
}

```
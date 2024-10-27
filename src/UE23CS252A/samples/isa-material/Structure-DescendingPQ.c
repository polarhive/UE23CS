#include <stdio.h>

#define MAX 10 // Maximum capacity of the priority queue

// Structure to represent an element in the priority queue
typedef struct {
    int data;
    int priority;
} Element;

// Array to store the priority queue elements
Element pq[MAX];
int size = 0; // Current size of the priority queue

// Function to check if the priority queue is empty
int isEmpty() {
    return size == 0;
}

// Function to check if the priority queue is full
int isFull() {
    return size == MAX;
}

// Function to insert an element into the priority queue (descending order of priority)
void push(int data, int priority) {
    if (isFull()) {
        printf("Priority Queue is full!\n");
        return;
    }

    int i;
    // Find the correct position to insert the new element based on its priority
    for (i = size - 1; i >= 0 && pq[i].priority < priority; i--) {
        pq[i + 1] = pq[i]; // Shift elements to make room
    }

    // Insert the new element
    pq[i + 1].data = data;
    pq[i + 1].priority = priority;
    size++;
}

// Function to remove and return the element with the highest priority (from the front)
int pop() {
    if (isEmpty()) {
        printf("Priority Queue is empty!\n");
        return -1; // Return a sentinel value to indicate empty queue
    }

    // The element with the highest priority is at the front (index 0)
    int highestPriorityData = pq[0].data;

    // Shift all the elements one position to the left
    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--; // Reduce the size of the queue
    return highestPriorityData;
}

// Function to get the element with the highest priority without removing it
int peek() {
    if (isEmpty()) {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    return pq[0].data; // The highest priority element is at index 0
}

// Driver code
int main() {
    // Insert elements into the priority queue
    push(4, 1); // Element 4 with priority 1
    push(5, 3); // Element 5 with priority 3
    push(6, 2); // Element 6 with priority 2
    push(7, 5); // Element 7 with priority 5 (highest priority)

    // Peek the element with the highest priority
    printf("Element with highest priority: %d\n", peek());

    // Remove elements from the priority queue in order of their priority
    printf("Removing elements in order of priority:\n");
    while (!isEmpty()) {
        printf("%d ", pop());
    }

    return 0;
}

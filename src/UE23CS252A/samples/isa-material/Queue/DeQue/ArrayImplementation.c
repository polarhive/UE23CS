#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define maximum size of the deque

int deque[MAX];
int front = -1;
int rear = -1;

// Function to check if the deque is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Function to check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element at the front of the deque
void insertFront(int key) {
    if (isFull()) {
        printf("Overflow: Unable to insert element at the front. Deque is full.\n");
        return;
    }

    if (front == -1) {  // If deque is initially empty
        front = MAX-1;
        rear = 0;
    } else if (front == 0) {
        front = MAX - 1;  // wrap around
    } else {
        front = front - 1;
    }

    deque[front] = key;
    printf("Inserted %d at the front.\n", key);
}

// Function to insert an element at the rear of the deque
void insertRear(int key) {
    if (isFull()) {
        printf("Overflow: Unable to insert element at the rear. Deque is full.\n");
        return;
    }

    if (rear == -1) {  // If deque is initially empty
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;  // wrap around
    } else {
        rear = rear + 1;
    }

    deque[rear] = key;
    printf("Inserted %d at the rear.\n", key);
}

// Function to delete an element from the front of the deque
void deleteFront() {
    if (isEmpty()) {
        printf("Underflow: Unable to delete element from the front. Deque is empty.\n");
        return;
    }

    int removed = deque[front];

    if (front == rear) {  // Deque has only one element
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;  // wrap around
    } else {
        front = front + 1;
    }

    printf("Deleted %d from the front.\n", removed);
}

// Function to delete an element from the rear of the deque
void deleteRear() {
    if (isEmpty()) {
        printf("Underflow: Unable to delete element from the rear. Deque is empty.\n");
        return;
    }

    int removed = deque[rear];

    if (front == rear) {  // Deque has only one element
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;  // wrap around
    } else {
        rear = rear - 1;
    }

    printf("Deleted %d from the rear.\n", removed);
}

// Function to display the deque
void displayDeque() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements are: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function to test the operations
int main() {
    insertRear(5);
    displayDeque();

    insertFront(15);
    displayDeque();
    
    insertRear(25);
    displayDeque();

    deleteFront();
    displayDeque();

    deleteRear();
    displayDeque();


    return 0;
}

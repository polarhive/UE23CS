#include <stdio.h>
#include <stdlib.h>

// Structure to store priority and processing time
typedef struct {
    int priority;
    int time;
} Task;

// Function to swap two Task elements
void swap(Task *a, Task *b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index i
void heapify(Task arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index

    // Check if left child exists and is "greater" than root (higher priority or shorter time)
    if (left < n && (arr[left].priority < arr[largest].priority || 
        (arr[left].priority == arr[largest].priority && arr[left].time < arr[largest].time))) {
        largest = left;
    }

    // Check if right child exists and is "greater" than largest so far
    if (right < n && (arr[right].priority < arr[largest].priority || 
        (arr[right].priority == arr[largest].priority && arr[right].time < arr[largest].time))) {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to implement heap sort 
void heapSort(Task arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // Move current root to end
        heapify(arr, i, 0); // call heapify on the reduced heap
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Task *arr = (Task *)malloc(n * sizeof(Task));

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].priority, &arr[i].time);
    }

    heapSort(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        printf("(%d, %d)\n", arr[i].priority, arr[i].time);
    }

    free(arr);
    return 0;
}

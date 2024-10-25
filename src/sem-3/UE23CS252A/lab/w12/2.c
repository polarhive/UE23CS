#include <stdio.h>
#include <stdlib.h>

// Structure to store a meeting with start and end times
typedef struct {
    int start;
    int end;
} Meeting;

// for min heap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Up(int heap[], int id) {
    while (id > 0 && heap[(id - 1) / 2] > heap[id]) {
        swap(&heap[(id - 1) / 2], &heap[id]);
        id = (id - 1) / 2;
    }
}

void Down(int heap[], int size, int id) {
    int smallest = id;
    int left = 2 * id + 1;
    int right = 2 * id + 2;

    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != id) {
        swap(&heap[id], &heap[smallest]);
        Down(heap, size, smallest);
    }
}

void insertHeap(int heap[], int *size, int value) {
    heap[(*size)++] = value;
    Up(heap, *size - 1);
}

int removeMinHeap(int heap[], int *size) {
    if (*size == 0) return -1;
    int minVal = heap[0];
    heap[0] = heap[--(*size)];
    Down(heap, *size, 0);
    return minVal;
}

// Comparison function for qsort to sort meetings by start time
int compare(const void *a, const void *b) {
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

// Function to find the minimum number of rooms required
int minMeetingRooms(Meeting meetings[], int n) {
    if (n == 0) return 0;

    qsort(meetings, n, sizeof(Meeting), compare);
    int *minHeap = (int *)malloc(n * sizeof(int));
    int heapSize = 0;

    insertHeap(minHeap, &heapSize, meetings[0].end);
    for (int i = 1; i < n; i++) {
        if (meetings[i].start >= minHeap[0])
            removeMinHeap(minHeap, &heapSize); // (meeting has ended)
        insertHeap(minHeap, &heapSize, meetings[i].end);
    }

    free(minHeap);
    return heapSize;
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting *meetings = (Meeting *)malloc(n * sizeof(Meeting));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    int rooms = minMeetingRooms(meetings, n);
    printf("%d\n", rooms);

    free(meetings);  // Free allocated memory
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY -1

typedef struct {
    int *buffer;
    int front;
    int rear;
    int size;
} CircularBuffer;

void initBuffer(CircularBuffer *cb, int size) {
    cb->size = size;
    cb->buffer = (int *)malloc(size * sizeof(int));
    cb->front = -1;
    cb->rear = -1;
}

int isFull(CircularBuffer *cb) {
    return (cb->front == (cb->rear + 1) % cb->size); }

int isEmpty(CircularBuffer *cb) {
    return (cb->front == -1);
}

void addPacket(CircularBuffer *cb, int packet_id) {
    if (isFull(cb)) {
        return;
    }
    if (isEmpty(cb)) {
        cb->front = 0;
    }
    cb->rear = (cb->rear + 1) % cb->size;
    cb->buffer[cb->rear] = packet_id;
}

int removePacket(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        return EMPTY;
    }
    int removed_packet = cb->buffer[cb->front];
    if (cb->front == cb->rear) {
        // The buffer has only one element, so reset the buffer
        cb->front = -1;
        cb->rear = -1;
    } else {
        cb->front = (cb->front + 1) % cb->size;
    }
    return removed_packet;
}

void displayBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer is empty.\n");
        return;
    }
    printf("Buffer elements: ");
    int i = cb->front;
    while (1) {
        printf("%d ", cb->buffer[i]);
        if (i == cb->rear) {
            break;
        }
        i = (i + 1) % cb->size;
    }
    printf("\n");
}

void freeBuffer(CircularBuffer *cb) {
    free(cb->buffer);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);  

    CircularBuffer cb;
    initBuffer(&cb, n);

    for (int i = 0; i < m; i++) {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "ADD") == 0) {
            int packet_id;
            scanf("%d", &packet_id);
            addPacket(&cb, packet_id);
        } else if (strcmp(command, "REMOVE") == 0) {
            int removed = removePacket(&cb);
            if (removed != EMPTY) {
                printf("%d\n", removed);
            }
        } else if (strcmp(command, "DISPLAY") == 0) {
            displayBuffer(&cb);
        }
    }

    freeBuffer(&cb);
    return 0;
}

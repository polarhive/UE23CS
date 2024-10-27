#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int remaining_time;
} Student;

typedef struct {
    Student *students;
    int front, rear, size;
    unsigned capacity;
} Queue;

Queue* createQueue(unsigned capacity);
void enqueue(Queue* queue, Student item);
Student dequeue(Queue* queue);
int isEmpty(Queue* queue);
int isFull(Queue* queue);

void roundRobinScheduling(Queue* queue, int T) {
    int finished_order[queue->capacity];  // order of students finishing
    int finished_count = 0;               // students who have finished

    while (!isEmpty(queue)) {
        Student current_student = dequeue(queue);

        // they finished
        if (current_student.remaining_time <= T) {
            finished_order[finished_count] = current_student.id;
            finished_count++;
        } else {
            // enqueue them back into the queue
            current_student.remaining_time -= T;
            enqueue(queue, current_student);
        }
    }

    for (int i = 0; i < finished_count; i++) {
        printf("%d ", finished_order[i]);
    }
    printf("\n");
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    int times[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &times[i]);
    }

    Queue* queue = createQueue(N);

    for (int i = 0; i < N; i++) {
        Student student = {i + 1, times[i]};  // from 1
        enqueue(queue, student);
    }

    roundRobinScheduling(queue, T);
    return 0;
}

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->students = (Student*)malloc(queue->capacity * sizeof(Student));
    return queue;
}

void enqueue(Queue* queue, Student item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->students[queue->rear] = item;
    queue->size = queue->size + 1;
}

Student dequeue(Queue* queue) {
    Student item = queue->students[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

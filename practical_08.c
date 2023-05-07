#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int priority;
    int data;
} QueueElement;

typedef struct {
    QueueElement elements[MAX_QUEUE_SIZE];
    int front, rear;
} PriorityQueue;

void initQueue(PriorityQueue *queue) {
    queue->front = queue->rear = -1;
}

int isQueueEmpty(PriorityQueue *queue) {
    return queue->front == -1;
}

int isQueueFull(PriorityQueue *queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

void enqueue(PriorityQueue *queue, QueueElement element) {
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
        queue->elements[queue->rear] = element;
        return;
    }
    
    int i = queue->rear;
    while (i >= queue->front && queue->elements[i].priority > element.priority) {
        queue->elements[(i + 1) % MAX_QUEUE_SIZE] = queue->elements[i];
        i = (i - 1) % MAX_QUEUE_SIZE;
    }
    
    queue->elements[(i + 1) % MAX_QUEUE_SIZE] = element;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
}

QueueElement dequeue(PriorityQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        QueueElement nullElement = {0, 0};
        return nullElement;
    }
    
    QueueElement dequeued = queue->elements[queue->front];
    
    if (queue->front == queue->rear) {
        initQueue(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    
    return dequeued;
}

void printQueue(PriorityQueue *queue) {
    printf("Queue contents: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("(%d, %d) ", queue->elements[i].priority, queue->elements[i].data);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("(%d, %d)\n", queue->elements[i].priority, queue->elements[i].data);
}

int main() {
    PriorityQueue queue;
    initQueue(&queue);
    
    enqueue(&queue, (QueueElement) {1, 10});
    enqueue(&queue, (QueueElement) {2, 20});
    enqueue(&queue, (QueueElement) {1, 30});
    enqueue(&queue, (QueueElement) {3, 40});
    enqueue(&queue, (QueueElement) {2, 50});
    
    printQueue(&queue);
    
    QueueElement dequeued = dequeue(&queue);
    printf("Dequeued element: (%d, %d)\n", dequeued.priority, dequeued.data);
    
    printQueue(&queue);
    
    enqueue(&queue, (QueueElement) {4, 60});
    
    printQueue(&queue);
    
    return 0;
}


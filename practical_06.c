#include <stdio.h>
#define MAXSIZE 10

int queue[MAXSIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAXSIZE - 1) {
        printf("\nQueue is full\n");
        return;
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty\n");
        return;
    } else {
        printf("\nDeleted %d from queue\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("\nQueue is empty\n");
        return;
    } else {
        printf("\nElements of queue are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to be added to queue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (choice != 4);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull()
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int item)
{
    if (isFull())
    {
        printf("\nQueue is full.\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = item;
    printf("\nInserted element: %d\n", item);
}

int dequeue()
{
    int item;
    if (isEmpty())
    {
        printf("\nQueue is empty.\n");
        exit(1);
    }
    item = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }
    return item;
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nQueue elements:\n");
    for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
    {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[i]);
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element to insert: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            printf("\nDeleted element: %d\n", dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice.\n");
        }
    }
    return 0;
}


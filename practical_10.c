#include <stdio.h>
#include <stdlib.h>

// structure to define a node
struct Node {
    int data;
    struct Node *next;
};

// function to add a new node at the beginning of the circular linked list
void addNode(struct Node **head, int data) {
    // create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    // check if the linked list is empty
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        // traverse to the last node
        struct Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }

        // add the new node at the beginning and update the last node's next pointer
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

// function to display the circular linked list
void display(struct Node *head) {
    // check if the linked list is empty
    if (head == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }

    // traverse through the circular linked list and print the nodes
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// main function
int main() {
    struct Node *head = NULL;

    // add nodes to the circular linked list
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);
    addNode(&head, 20);

    // display the circular linked list
    printf("Circular Linked List: ");
    display(head);

    return 0;
}


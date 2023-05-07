#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct node {
    int data;
    struct node* next;
};

// Define a function to add a node at the beginning of a linked list
void push(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Define a function to traverse a linked list and print the data
void traverse(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Initialize an empty linked list
    struct node* head = NULL;

    // Add nodes to the beginning of the linked list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);

    // Traverse the linked list and print the data
    traverse(head);

    return 0;
}


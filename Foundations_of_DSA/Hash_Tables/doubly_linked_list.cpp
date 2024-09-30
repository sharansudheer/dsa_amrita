// C Program to insert a node at the beginning of doubly
// linked list

#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev
};

// Function to create a new node
struct Node *createNode(int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to insert a new node at the front of doubly linked list
struct Node *insertAtFront(struct Node *head, int new_data) {

    // Create a new node
    struct Node *new_node = createNode(new_data);

    // Make next of new node as head
    new_node->next = head;

    // Change prev of head node to new node
    if (head != NULL) {
        head->prev = new_node;
    }

    // Return the new node as the head of the doubly linked list
    return new_node;
}

// Function to print the doubly linked list
void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf(" %d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {

    // Create a hardcoded doubly linked list:
    // 2 <-> 3 <-> 4 
    struct Node *head = createNode(2);
    head->next = createNode(3);
    head->next->prev = head;
    head->next->next = createNode(4);
    head->next->next->prev = head->next;

    // Print the original list
    printf("Original Linked List:");
    printList(head);

    // Insert a new node at the front of the list
    printf("After inserting Node at the front:");
    int data = 1;
    head = insertAtFront(head, data);

    // Print the updated list
    printList(head);

    return 0;
}

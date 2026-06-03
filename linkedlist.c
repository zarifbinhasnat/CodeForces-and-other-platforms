#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to delete a node
void delete_node(int d, node** head) {
    node* temp = *head;
    node* prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == d) {
        *head = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != d) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Node with data %d not found\n", d);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

// Function to insert a node
void insert_node(int d, int prevdata, node** head) {
    node* temp = *head;
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Search for the node with the specified data
    while (temp != NULL && temp->data != prevdata) {
        temp = temp->next;
    }

    // If the node was not found, print an error message
    if (temp == NULL) {
        printf("Node with data %d not found\n", prevdata);
        free(newNode); // Free the allocated memory for the new node
        return;
    }

    // Insert the new node after the found node
    newNode->next = temp->next;
    temp->next = newNode;
}
void linklist(node** head) {
    int n;
    printf("Enter the number of nodes you want to create\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int d;
        printf("Enter the data of node %d\n", i + 1);
        scanf("%d", &d);

        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = d;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void print_list(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    node* head = NULL;
    linklist(&head);

    while (1) {
        printf("1. Insert a node after a node\n");
        printf("2. Delete a node\n");

        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int d, prevdata;
            printf("Enter the data of the new node\n");
            scanf("%d", &d);
            printf("Enter the data of the node after which you want to insert the new node\n");
            scanf("%d", &prevdata);
            insert_node(d, prevdata, &head);
        } else if (choice == 2) {
            int d;
            printf("Enter the data of the node you want to delete\n");
            scanf("%d", &d);
            delete_node(d, &head);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    // Free remaining nodes in the list
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
print_list(head);
    return 0;
}

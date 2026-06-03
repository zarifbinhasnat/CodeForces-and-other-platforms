#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}Node;
void insertAfterNode(Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("The given previous node cannot be NULL");
        return;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void insertnodeattheendofthelinkedlist

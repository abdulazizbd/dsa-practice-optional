// Implementation of singly linked list & display this list
// Find length of a linked list
#include <stdio.h>
#include <stdlib.h>

void createSLL(int);
void display();
int lengthSLL();

struct Node
{
    int data;
    struct Node *next;
} * head;

int main()
{
    int nodes;
    createSLL(5);
    display();
    nodes = lengthSLL();
    printf("\nNo. of nodes in your linked list is: %d", nodes);

    return 0;
}

void createSLL(int size)
{
    struct Node *newNode, *temp;
    int i;
    head = NULL;
    for (int i; i <= size; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for pos 1: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = temp = newNode;

        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void display()
{
    struct Node *temp;
    temp = head;
    printf("Liked list is: ");
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int lengthSLL()
{
    struct Node *temp;
    temp = head;
    int length = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}
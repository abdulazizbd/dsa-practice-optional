// Implementation of singly linked list & display this list
#include <stdio.h>
#include <stdlib.h>

void createSCLL(int);
void displaySCLL();

struct Node
{
    int data;
    struct Node *next;
} * head;

int main()
{
    createSCLL(5);
    printf("Your Linked List is: ");
    displaySCLL();

    return 0;
}

void createSCLL(int size)
{
    struct Node *newNode, *temp;
    int i;
    head = NULL;
    for (i = 1; i <= size; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for pos %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = temp = newNode;
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        // if there is only one node.
        temp->next = head;
        /*
            We can also write:
            newNode->next = head;
        */
    }
}

void displaySCLL()
{
    struct Node *temp;
    if (head == NULL)
        printf("There is no node is this list");
    else
    {
        temp = head;
        while (temp->next != head)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}
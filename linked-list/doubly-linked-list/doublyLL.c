// implementation of linked list & display this list
#include <stdio.h>
#include <stdlib.h>

void createDLL(int);
void displayDLL();

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} * head;

int main()
{
    createDLL(5);
    printf("Your doubly linked list is: ");
    displayDLL();

    return 0;
}

void createDLL(int size)
{
    struct Node *newNode, *temp;
    int i;

    head = NULL;
    for (i = 1; i <= size; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for pos %d: ", i);
        scanf("%d", &newNode->data);
        newNode->prev = 0;
        newNode->next = 0;

        if (head == 0)
            head = temp = newNode;
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
}

void displayDLL()
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
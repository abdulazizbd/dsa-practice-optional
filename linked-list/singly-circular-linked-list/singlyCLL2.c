// Implementation of singly linked list & display this list: using only tail pointer
#include <stdio.h>
#include <stdlib.h>

void createSCLL(int);
void displaySCLL();

struct Node
{
    int data;
    struct Node *next;
} * tail;

int main()
{
    createSCLL(5);
    printf("Your Linked List is: ");
    displaySCLL();

    return 0;
}

void createSCLL(int size)
{
    struct Node *newNode;
    int i;
    tail = NULL;

    for (i = 1; i <= size; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for pos %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (tail == NULL)
        {
            tail = newNode;
            tail->next = newNode;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = tail->next;
        }
    }
}

void displaySCLL()
{
    struct Node *temp;
    if (tail == NULL)
        printf("There is no node in this list!");
    else
    {
        temp = tail->next;
        while (temp->next != tail->next)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}
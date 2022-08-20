// Implementation of Doubly Circular Linked List & Display the list
#include <stdio.h>
#include <stdlib.h>

void createDCLL(int);
void displayDCLL();

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} * head, *tail;

int main()
{
    createDCLL(5);
    printf("Your liked list is: ");
    displayDCLL();

    return 0;
}

void createDCLL(int size)
{
    struct Node * newNode;
    int i;
    head = tail = NULL;
    for (i = 1; i <= size; i++)
    {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        printf("Enter data for position %d: ", i);
        scanf("%d", &newNode->data);
        newNode->prev = 0;
        newNode->next = 0;

        if (head == NULL)
        {
            head = tail = newNode;
            head->prev = newNode;
            head->next = newNode;
        }
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = tail->next;
        }
    }
}

void displayDCLL()
{
    struct Node * temp;
    temp = head;
    
    if (head == NULL)
        printf("There is no node in this list!");
    else
    {
        while (temp != tail)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data); 
    }
}
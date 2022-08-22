// Basic operations on linked list (i.e. creation, display, finding length, search, insertion & deletion)
#include <stdio.h>
#include <stdlib.h>

void createSLL(int);
void display();
int lengthSLL();
int searchInSLL(int);
void insertAtBeginning(int);
void insertAtEnd(int);
void insertAtPosition(int, int);
void dltFromBeginning();
void dltFromEnd();
void dltFromPos(int);
void reverseSLL();

struct Node
{
    int data;
    struct Node *next;
} * head;

int main()
{
    int nodes, result;

    createSLL(5);
    nodes = lengthSLL();
    printf("\nNo. of nodes in your linked list is: %d", nodes);
    display();

    result = searchInSLL(20);
    if(result != -1)
        printf("\nElement is found at node: %d", result);
    else 
        printf("\nElement is not present!");

    insertAtBeginning(5);
    display();

    dltFromBeginning();
    display();

    insertAtEnd(60);
    display();

    dltFromEnd();
    display();

    insertAtPosition(1, 3);
    display();

    dltFromPos(1);
    display();

    insertAtPosition(5, 70);
    display();

    dltFromPos(5);
    display();

    insertAtPosition(3, 25);
    display();

    dltFromPos(3);
    display();

    reverseSLL();
    display();

    reverseSLL();
    display();

    return 0;
}

void createSLL(int size)
{
    int i;
    struct Node *newNode, *temp;
    head = NULL;
    for (i = 1; i <= size; i++)
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
    printf("\nLinked list is: ");
    while (temp != NULL)
    {
        printf("%4d", temp->data);
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

int searchInSLL(int data)
{
    int i;
    struct Node * temp;
    temp = head;

    i = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
            return i;
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
        return -1;
}

void insertAtBeginning(int data)
{
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    temp = head;
    head = newNode;
    newNode->next = temp;
}

void insertAtEnd(int data)
{
    struct Node *newNode, *temp;
    temp = head;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtPosition(int position, int data)
{
    int length;
    length = lengthSLL();

    if (position < 1 && position > length)
        printf("Warning: invalid position to enter!");

    else
    {
        struct Node *newNode, *temp;
        temp = head;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == 0)
            head = newNode;

        else
        {
            if (position == 1)
                insertAtBeginning(data);

            else if (position == length + 1)
                insertAtEnd(data);

            else
            {
                int i = 1;
                while (i < position - 1)
                {
                    temp = temp->next;
                    i++;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
}

void dltFromBeginning()
{
    struct Node *temp;
    temp = head;
    head = temp->next;
    free(temp);
}

void dltFromEnd()
{
    struct Node *temp, *prevNode;
    temp = head;
    prevNode = NULL;

    while (temp->next != NULL)
    {
        prevNode = temp;
        temp = temp->next;
    }
    prevNode->next = NULL;
    free(temp);
}

void dltFromPos(int position)
{
    int length;
    length = lengthSLL();

    if (position < 1 && position > length)
        printf("Warning: invalid position to delete!");

    else
    {
        if (head == 0)
            printf("There is no node to delete");
        else
        {
            if (position == 1)
                dltFromBeginning();

            else if (position == length)
                dltFromEnd();
            
            else 
            {
                int i;
                struct Node *temp, *nextNode;
                temp = head;
                nextNode = temp->next;

                i = 1;
                while (i < position - 1)
                {
                    temp = nextNode;
                    nextNode = nextNode->next;
                    i++;
                }
                temp->next = nextNode->next;

                free(nextNode);
            }
        }
    }
}

void reverseSLL()
{
    struct Node *prevNode, *currentNode, *nextNode;
    currentNode = nextNode = head;
    prevNode = NULL;
    while (nextNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
}
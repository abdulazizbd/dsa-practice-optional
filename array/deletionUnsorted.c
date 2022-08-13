// Implementation of deletion of an elements from an Unsorted Array
#include <stdio.h>

void printArray(int[], int);
int linearSearch(int[], int, int);
int deleteElements(int[], int, int *);

int main()
{
    int i, count, value, result;
    int arr[50] = {20, 10, 30, 40, 60, 70, 50, 90, 80, 100};

    count = 0;
    while (arr[i++])
        ++count;

    printf("Before insert Elements ");
    printArray(arr, count);

    printf("\nEnter value: ");
    scanf("%d", &value);

    result = deleteElements(arr, value, &count);

    if (result != -1)
    {
        printf("After insert Elements ");
        printArray(arr, count);
    }
    else 
        printf("Warning: Invalid element to be delete!");

    return 0;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d  ", arr[i]);
}

int linearSearch(int arr[], int size, int key)
{
    int i;
    for (i = 0; i < size; i++)
        if (key == arr[i])
            return i;

    return -1;
}

int deleteElements(int arr[], int value, int *count)
{
    int index = linearSearch(arr, *count, value);

    if (index != -1)
    {
        // As sorting of data is not mandatory, we can transfer the last value in the index of deleted element.
        arr[index] = arr[*count - 1];
        --*count;
        return 1;
    }
    else
        return -1;
}
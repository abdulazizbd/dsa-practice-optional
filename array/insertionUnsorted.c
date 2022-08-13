// Implementation of insertion in an Unsorted Array
#include <stdio.h>

void printArray(int[], int);
void insertElements(int[], int *, int, int);

int main()
{
    int i, count, index, indexValue;
    int arr[50] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    count = 0;
    while (arr[i++])
        ++count;

    printf("Before insert Elements ");
    printArray(arr, count);

    printf("\nEnter index: ");
    scanf("%d", &index);
    printf("Enter value for this index: ");
    scanf("%d", &indexValue);

    if (index >= 0 && index <= count)
    {
        insertElements(arr, &count, index, indexValue);

        printf("After insert Elements ");
        printArray(arr, count);
    }
    else
        printf("Warning: Invalid index value! Valid range is: 0 to %d", count);

    return 0;
}

void printArray(int arr[], int size)
{
    int i;
    printf("Array: ");
    for (i = 0; i < size; i++)
        printf("%d  ", arr[i]);
}

void insertElements(int arr[], int *count, int index, int indexValue)
{
    // As sorting of data is not mandatory, we can transfer the specific positions value in last and insert desired value in this position
    int temp;
    temp = arr[index];
    arr[index] = indexValue;
    arr[*count] = temp;

    ++(*count);
}
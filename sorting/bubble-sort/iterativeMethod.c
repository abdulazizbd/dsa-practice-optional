// Implementation of bubble sort using iterative method
#include <stdio.h>

void printArray(int[], int );
void swap(int *, int *);
void bubbleSort(int[], int );

int main()
{
    int arr[] = {40, 60, 30, 20, 80, 90, 0, 100};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting ");
    printArray(arr, size);

    bubbleSort(arr, size);
    printf("\nAfter Sorting  ");
    printArray(arr, size);

    return 0;
}

void printArray(int arr[], int size)
{
    int i;
    printf("Your array is: ");
    for (i = 0; i < size; i++)
        printf("%d  ", *(arr + i));
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        int flag = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }

        if (!flag)
            break;
    }
}
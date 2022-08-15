// Implementation of insertion sort using iterative method
#include<stdio.h>

void printArray(int [], int );
void insertionSort(int [], int );

int main() 
{
    int size, arr[] = {60, 20, 50, 80, 90 , 0, 100, 0, 100, 80, 60};

    size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting ");
    printArray(arr, size);

    insertionSort(arr, size);

    printf("\nAfter sorting  ");
    printArray(arr, size);

    return 0;
}

void printArray(int arr[], int size)
{
    int i;
    printf("Your array is: ");
    for (i = 0; i < size; i++)
        printf("%5d", arr[i]);
}

void insertionSort(int arr[], int size)
{
    int i, j;
    for (i = 1; i < size; i++)
    {
        int temp = arr[i];
        j = i -1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
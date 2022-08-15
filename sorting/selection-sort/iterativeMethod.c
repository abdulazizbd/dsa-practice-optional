// Implementation of selection sort using iterative method
#include<stdio.h>

void printArray(int [], int );
void swap(int *, int *);
void selectionSort(int [], int );

int main() 
{
    int size, arr[] = {60, 20, 50, 80, 90 , 0, 100, 0, 100, 80, 60};

    size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting ");
    printArray(arr, size);

    selectionSort(arr, size);

    printf("\nAfter sorting  ");
    printArray(arr, size);

    return 0;
}

void printArray(int arr[], int size)
{
    int i;
    printf("Your array is");
    for (i = 0; i < size - 1; i++)
        printf("%5d", arr[i]);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size)
{
    int i, j, min;
    
    for (i = 0; i < size -1; i++)
    {
        int min = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;
        
        if (min != i)
            swap(&arr[i], &arr[min]);
    }
}
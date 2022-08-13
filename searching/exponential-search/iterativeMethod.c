// Exponential Search - iterative method
#include <stdio.h>

void printArray(int [], int);
int min(int , int );
int exponentialSearch(int [], int , int );
int binarySearch(int [], int , int , int );

int main()
{
	int key, size, result, arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	printf("\nEnter number: ");
	scanf("%d", &key);

	result = exponentialSearch(arr, size, key);

	if (result != -1)
		printf("Element is found at index: %d", result);
	else
		printf("Element is not found!");

	return 0;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d  ", arr[i]);
}

int min(int numOne, int numTwo)
{
    if (numOne > numTwo)
        return numTwo;
    else 
        return numOne;
}

int exponentialSearch(int arr[], int size, int key)
{
    if (arr[0] == key)
        return 0;

    int i = 1;
    while (i < size && arr[i] <= key)
        i *= 2;

    return binarySearch(arr, i/2, min(i, size -1), key);
}

int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
       int mid = low + (high - low) / 2;

       if (key == arr[mid])
            return mid;

        if (key > arr[mid])
            low = mid + 1;
        else 
            high = mid - 1; 
    }

    return -1;
}
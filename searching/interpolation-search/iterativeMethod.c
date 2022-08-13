// Interpolation Search - iterative method
#include <stdio.h>

void printArray(int [], int);
int interpolationSearch(int [], int , int , int );

int main()
{
	int key, size, result, arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	printf("\nEnter number: ");
	scanf("%d", &key);

	result = interpolationSearch(arr, 0, size - 1, key);

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

int interpolationSearch(int arr[], int low, int high, int key)
{
    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        int pos = low + (((double) (high - low) / (arr[high] - arr[low])) * (key - arr[low]));
        
        if (arr[pos] == key)
            return pos;

        if (arr[pos] < key)
            low = pos + 1;
        if (arr[pos] > key)
            high = pos -1;
    }

    return -1;
}
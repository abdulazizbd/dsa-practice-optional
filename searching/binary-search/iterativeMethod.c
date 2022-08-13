// Binary Search - Iterative Method
#include <stdio.h>
void printArray(int[], int);
int binarySearch(int[], int, int);

int main()
{
	int key, size, result, arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	printf("\nEnter number: ");
	scanf("%d", &key);

	result = binarySearch(arr, size, key);

	if (result != -1)
		printf("Element is found at index: %d", result);
	else
		printf("Element is not found!");

	return 0;
}

void printArray(int arr[], int size)
{
	int i = 0;
	printf("Your array is: ");
	for (i = 0; i < size; i++)
		printf("%d  ", arr[i]);
}

int binarySearch(int arr[], int size, int key)
{
	int low, mid, high;

	low = 0;
	high = size -1;

	while (low <= high)
	{
	    mid = low + (high - low) / 2;

		if (arr[mid] == key)
			return mid;
            
		if (arr[mid] < key) 
			low = mid + 1;
		else 
			high = mid -1;	
	}

	return -1;
}
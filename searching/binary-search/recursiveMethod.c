// Binary Search - Recursive Method 
#include <stdio.h>
void printArray(int[], int);
int binarySearch(int[], int, int, int);

int main()
{
	int key, size, result, arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	printf("\nEnter number: ");
	scanf("%d", &key);

	result = binarySearch(arr, 0, size-1, key);

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

int binarySearch(int arr[], int low, int high, int key)
{
	if (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == key)
			return mid;

		if (arr[mid] < key)
			return binarySearch(arr, mid + 1, high, key);

		return binarySearch(arr, low, mid -1, key);		
	}

	return -1;	
}
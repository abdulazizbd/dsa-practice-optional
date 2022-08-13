#include <stdio.h>
void printArray(int [], int);
int ternarySearch(int [], int, int, int); 

int main()
{
	int key, size, result, arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	printf("\nEnter number: ");
	scanf("%d", &key);

	result = ternarySearch(arr, 0, size - 1, key); 

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

int ternarySearch(int arr[], int low, int high, int key)
{
	if (low <= high)
	{
		int mid1 = low + (high - low) / 3;
		int mid2 = high - (high - low) / 3;

		if (key == arr[mid1])
			return mid1;
		if (key == arr[mid2])
			return mid2;

		if (key < arr[mid1])
			return ternarySearch(arr, low, mid1 -1, key);
		if (key > arr[mid2])
			return ternarySearch(arr, mid2 + 1, high, key);

		return ternarySearch(arr, mid1 + 1, mid2 -1, key);
	}
	
	return -1;
}
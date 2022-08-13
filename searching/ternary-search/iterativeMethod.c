// Ternary Search - iterative method
#include <stdio.h>
void printArray(int [], int);
int ternarySearch(int [], int, int);

int main()
{
	int key, size, result, arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	printf("\nEnter number: ");
	scanf("%d", &key);

	result = ternarySearch(arr, size, key);

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

int ternarySearch(int arr[], int size, int key)
{
	int low, mid1, mid2, high;

	low = 0;
	high = size -1;

	while (low <= high)
	{
		mid1 = low + (high - low) / 3;
		mid2 = high - (high - low) / 3;

		if (key == arr[mid1])
			return mid1;
		if (key == arr[mid2])
			return mid2;

		if (key < arr[mid1])
			high = mid1 -1;
		else if (key > arr[mid2])
			low = mid2 + 1;
		else 
		{
			low = mid1 + 1;
			high = mid2 - 1;
		}	
	}
	
	return -1;
}
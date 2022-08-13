// Jump Search - iterative method
#include <stdio.h>
#include <math.h>

void printArray(int [], int);
int min(int , int );
int jumpSearch(int [], int , int);

int main()
{
	int key, size, result, arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	printf("\nEnter number: ");
	scanf("%d", &key);

	result = jumpSearch(arr, size, key);

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

int jumpSearch(int arr[], int size, int key)
{
    int prev = 0;
    int step = sqrt(size);

    while (arr[min(step, size) - 1] < key)
    {
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return -1;
    }

    while (arr[prev] < key)
    {
        prev++;

        if (prev == min(step, size))
            return -1;
    }

    if (arr[prev] == key)
        return prev;

    return -1;
}
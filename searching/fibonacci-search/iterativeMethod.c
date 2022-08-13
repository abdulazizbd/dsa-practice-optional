// Fibonacci Search - iterative method
#include <stdio.h>

void printArray(int [], int);
int min(int , int );
int fibonacciSearch(int [], int , int );

int main()
{
	int key, size, result, arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	printf("\nEnter number: ");
	scanf("%d", &key);

	result = fibonacciSearch(arr, size, key);

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

int min(int x, int y) { return (x > y) ? y : x; }

int fibonacciSearch(int arr[], int size, int key)
{
    int fibM2 = 0; 
    int fibM1 = 1;
    int fibM = fibM1  + fibM2;

    while (fibM < size)
    {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM1 + fibM2;
    }

    int offset = -1;
    while (fibM > 1)
    {
        int i = min(offset + fibM2, size - 1); 

        if (arr[i] == key)
            return i;
        
        if (arr[i] < key)
        {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        }
        else 
        {

            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        }
    }

    if (fibM1 && arr[offset + 1] == key)
        return offset + 1;
    
    return -1;
}
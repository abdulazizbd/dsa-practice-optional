// Implementation of traversal operation in an array
#include <stdio.h>

int main()
{
    int i, n, size, arr[50];

    size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter how many elements you want to insert (from 0 to %d): ", size);
    scanf("%d", &n);

    if (n <= size)
    {
        printf("Enter %d elements: ", n);
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        printf("Elements you entered are: ");
        for (i = 0; i < n; i++)
            printf("%d  ", arr[i]);
    }
    else {
        printf("Warning: You can't enter %d numbers. Try to use from 0 to %d", n, size);
    }

    return 0;
}
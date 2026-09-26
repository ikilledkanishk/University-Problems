//Problem Statement: Write a c program to implement Quick sort using divide and conquer method.
//Source Code:

#include <stdio.h>

#define MAX 100

// Partition the array
int partition(int arr[], int low, int high)
{
    int pivot, i, j, temp;

    pivot = arr[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct position
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort using Divide and Conquer
void quickSort(int arr[], int low, int high)
{
    int pivotIndex;

    if (low < high)
    {
        // Divide
        pivotIndex = partition(arr, low, high);

        // Conquer
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int arr[MAX];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Array after Quick Sort:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
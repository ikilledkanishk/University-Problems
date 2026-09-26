//Problem Statement: Write a c program to implement Merge sort using divide and conquer method.
//Source Code:

#include <stdio.h>

#define MAX 100

// Merge two sorted subarrays
void merge(int arr[], int low, int mid, int high)
{
    int temp[MAX];
    int i = low;
    int j = mid + 1;
    int k = low;

    // Compare and merge elements
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from left subarray
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from right subarray
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy sorted elements back to original array
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

// Merge Sort using Divide and Conquer
void mergeSort(int arr[], int low, int high)
{
    int mid;

    if (low < high)
    {
        // Divide
        mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Conquer and combine
        merge(arr, low, mid, high);
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

    mergeSort(arr, 0, n - 1);

    printf("Array after Merge Sort:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
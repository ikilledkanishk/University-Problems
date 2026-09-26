/*Problem Statement: Write a menu driven c program to implement the following searching algorithms
a. Linear search
b. Binary search
c. Interpolation search*/

//Source Code:
#include <stdio.h>

#define MAX 100

// Linear Search
int linearSearch(int arr[], int n, int key)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Interpolation Search
int interpolationSearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1, pos;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        if (arr[low] == arr[high])
        {
            if (arr[low] == key)
                return low;
            else
                return -1;
        }

        pos = low + ((key - arr[low]) * (high - low))
                    / (arr[high] - arr[low]);

        if (arr[pos] == key)
            return pos;

        else if (arr[pos] < key)
            low = pos + 1;

        else
            high = pos - 1;
    }

    return -1;
}

int main()
{
    int arr[MAX], n, key, choice, result;
    int i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in ascending order:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n--- SEARCH MENU ---\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Interpolation Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3)
        {
            printf("Enter the element to search: ");
            scanf("%d", &key);
        }

        switch (choice)
        {
            case 1:
                result = linearSearch(arr, n, key);

                if (result != -1)
                    printf("Element found at position %d.\n", result + 1);
                else
                    printf("Element not found.\n");

                break;

            case 2:
                result = binarySearch(arr, n, key);

                if (result != -1)
                    printf("Element found at position %d.\n", result + 1);
                else
                    printf("Element not found.\n");

                break;

            case 3:
                result = interpolationSearch(arr, n, key);

                if (result != -1)
                    printf("Element found at position %d.\n", result + 1);
                else
                    printf("Element not found.\n");

                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}

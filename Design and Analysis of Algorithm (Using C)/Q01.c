//Problem Statement: Using Divide and Conquer Technique write a C program to implement Binary Search. Mention the Compiler used in your program.
//Source Code:

#include <stdio.h>
int binarySearch(int a[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (a[mid] == key)
        return mid;
    else if (key < a[mid])
        return binarySearch(a, low, mid - 1, key);
    else
        return binarySearch(a, mid + 1, high, key);
}

int main()
{
    int n, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements in sorted order:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(a, 0, n - 1, key);

    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at position %d.\n", result + 1);

    return 0;
}

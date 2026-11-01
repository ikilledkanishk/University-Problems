//Using Divide and Conquer Technique write a C program to implement quick sort.
//Source Code:

#include <stdio.h>

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[high];
        int i = low - 1, temp;

        for (int j = low; j < high; j++)
        {
            if (a[j] < pivot)
            {
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int pi = i + 1;

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    int n, a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

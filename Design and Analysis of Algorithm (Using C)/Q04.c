//Using Divide and Conquer Technique write a C program to implement max-min problem.
//Source Code:

#include <stdio.h>

struct MinMax
{
    int min;
    int max;
};

struct MinMax maxMin(int a[], int low, int high)
{
    struct MinMax result, left, right;

    if (low == high)
    {
        result.min = result.max = a[low];
        return result;
    }

    if (high == low + 1)
    {
        if (a[low] < a[high])
        {
            result.min = a[low];
            result.max = a[high];
        }
        else
        {
            result.min = a[high];
            result.max = a[low];
        }
        return result;
    }

    int mid = (low + high) / 2;

    left = maxMin(a, low, mid);
    right = maxMin(a, mid + 1, high);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main()
{
    int n, a[100];
    struct MinMax result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    result = maxMin(a, 0, n - 1);

    printf("Minimum element = %d\n", result.min);
    printf("Maximum element = %d\n", result.max);

    return 0;
}

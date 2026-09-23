 //Problem Statement: Write a menu driven C program to implement the following using a 1D array with 
//existing elements:
//a. Insert a new element at any position
//b. Delete an existing element from any position
//c. Display the elements

//Source Code:
#include <stdio.h>

int main()
{
    int arr[100], n, choice, pos, value, i;

    printf("Enter the number of existing elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);

                if (pos < 1 || pos > n + 1)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    printf("Enter the element to insert: ");
                    scanf("%d", &value);

                    // Shift elements to the right
                    for (i = n; i >= pos; i--)
                    {
                        arr[i] = arr[i - 1];
                    }

                    arr[pos - 1] = value;
                    n++;

                    printf("Element inserted successfully.\n");
                }
                break;

            case 2:
                printf("Enter the position to delete (1 to %d): ", n);
                scanf("%d", &pos);

                if (pos < 1 || pos > n)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    // Shift elements to the left
                    for (i = pos - 1; i < n - 1; i++)
                    {
                        arr[i] = arr[i + 1];
                    }

                    n--;

                    printf("Element deleted successfully.\n");
                }
                break;

            case 3:
                printf("Array elements are:\n");

                for (i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }

                printf("\n");
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

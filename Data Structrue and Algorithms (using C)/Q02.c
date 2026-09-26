/*Problem Definition: Write a menu driven C program to implement the following operations in a Stack:
a. Insert new element at the top of the stack
b. Delete existing element from the top of the stack
c. Display the element/s of the stack*/

//Source Code:
#include <stdio.h>

#define MAX 100

int main()
{
    int stack[MAX];
    int top = -1;
    int choice, value, i;

    do
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Push
                if (top == MAX - 1)
                {
                    printf("Stack Overflow!\n");
                }
                else
                {
                    printf("Enter the element to insert: ");
                    scanf("%d", &value);

                    top++;
                    stack[top] = value;

                    printf("%d inserted into the stack.\n", value);
                }
                break;

            case 2:
                // Pop
                if (top == -1)
                {
                    printf("Stack Underflow!\n");
                }
                else
                {
                    printf("%d deleted from the stack.\n", stack[top]);
                    top--;
                }
                break;

            case 3:
                // Display
                if (top == -1)
                {
                    printf("Stack is empty!\n");
                }
                else
                {
                    printf("Stack elements are:\n");

                    for (i = top; i >= 0; i--)
                    {
                        printf("%d\n", stack[i]);
                    }
                }
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

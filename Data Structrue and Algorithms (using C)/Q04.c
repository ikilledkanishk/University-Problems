/*Problem Definition: Write a menu driven C program to implement the following operations in a Circular 
Queue:
a. Insert new element at the rear of this queue
b. Delete existing element from the front of this queue
c. Display the element/s of this queue*/

//Source Code:

#include <stdio.h>

#define MAX 5

int main()
{
    int queue[MAX];
    int front = -1, rear = -1;
    int choice, value, i;

    do
    {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Enqueue
                if ((rear + 1) % MAX == front)
                {
                    printf("Circular Queue Overflow!\n");
                }
                else
                {
                    printf("Enter the element to insert: ");
                    scanf("%d", &value);

                    if (front == -1)
                    {
                        front = 0;
                        rear = 0;
                    }
                    else
                    {
                        rear = (rear + 1) % MAX;
                    }

                    queue[rear] = value;

                    printf("%d inserted into the circular queue.\n", value);
                }
                break;

            case 2:
                // Dequeue
                if (front == -1)
                {
                    printf("Circular Queue Underflow!\n");
                }
                else
                {
                    printf("%d deleted from the circular queue.\n", queue[front]);

                    if (front == rear)
                    {
                        // Queue becomes empty
                        front = -1;
                        rear = -1;
                    }
                    else
                    {
                        front = (front + 1) % MAX;
                    }
                }
                break;

            case 3:
                // Display
                if (front == -1)
                {
                    printf("Circular Queue is empty!\n");
                }
                else
                {
                    printf("Circular Queue elements are:\n");

                    i = front;

                    while (1)
                    {
                        printf("%d ", queue[i]);

                        if (i == rear)
                            break;

                        i = (i + 1) % MAX;
                    }

                    printf("\n");
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
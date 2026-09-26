/*Problem Definition: Write a menu driven C program to implement the following operations in a Linear 
Queue:
a. Insert new element at the rear of this queue
b. Delete existing element from the front of this queue
c. Display the element/s of this queue*/

//Source Code:
#include <stdio.h>

#define MAX 100

int main()
{
    int queue[MAX];
    int front = -1, rear = -1;
    int choice, value, i;

    do
    {
        printf("\n--- LINEAR QUEUE MENU ---\n");
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
                if (rear == MAX - 1)
                {
                    printf("Queue Overflow!\n");
                }
                else
                {
                    printf("Enter the element to insert: ");
                    scanf("%d", &value);

                    if (front == -1)
                        front = 0;

                    rear++;
                    queue[rear] = value;

                    printf("%d inserted into the queue.\n", value);
                }
                break;

            case 2:
                // Dequeue
                if (front == -1 || front > rear)
                {
                    printf("Queue Underflow!\n");
                }
                else
                {
                    printf("%d deleted from the queue.\n", queue[front]);
                    front++;

                    // Reset queue when it becomes empty
                    if (front > rear)
                    {
                        front = -1;
                        rear = -1;
                    }
                }
                break;

            case 3:
                // Display
                if (front == -1)
                {
                    printf("Queue is empty!\n");
                }
                else
                {
                    printf("Queue elements are:\n");

                    for (i = front; i <= rear; i++)
                    {
                        printf("%d ", queue[i]);
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
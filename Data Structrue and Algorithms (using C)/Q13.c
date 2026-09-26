/*Problem Definition: Write a menu driven c program to implement operations of stack and queue using 
single linked list.*/

//Source Code:
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *stackTop = NULL;
struct Node *queueFront = NULL;
struct Node *queueRear = NULL;

// ---------------- STACK OPERATIONS ----------------

// Push element into stack
void push()
{
    struct Node *newNode;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the element: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = stackTop;
    stackTop = newNode;

    printf("%d pushed into the stack.\n", value);
}

// Pop element from stack
void pop()
{
    struct Node *temp;

    if (stackTop == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }

    temp = stackTop;

    printf("%d popped from the stack.\n", temp->data);

    stackTop = stackTop->next;

    free(temp);
}

// Display stack
void displayStack()
{
    struct Node *temp;

    if (stackTop == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }

    temp = stackTop;

    printf("Stack elements:\n");

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// ---------------- QUEUE OPERATIONS ----------------

// Enqueue element into queue
void enqueue()
{
    struct Node *newNode;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the element: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (queueFront == NULL)
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else
    {
        queueRear->next = newNode;
        queueRear = newNode;
    }

    printf("%d inserted into the queue.\n", value);
}

// Dequeue element from queue
void dequeue()
{
    struct Node *temp;

    if (queueFront == NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }

    temp = queueFront;

    printf("%d deleted from the queue.\n", temp->data);

    queueFront = queueFront->next;

    if (queueFront == NULL)
    {
        queueRear = NULL;
    }

    free(temp);
}

// Display queue
void displayQueue()
{
    struct Node *temp;

    if (queueFront == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    temp = queueFront;

    printf("Queue elements:\n");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// ---------------- MAIN FUNCTION ----------------

int main()
{
    int choice;

    do
    {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                int stackChoice;

                do
                {
                    printf("\n------ STACK MENU ------\n");
                    printf("1. Push\n");
                    printf("2. Pop\n");
                    printf("3. Display Stack\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &stackChoice);

                    switch (stackChoice)
                    {
                        case 1:
                            push();
                            break;

                        case 2:
                            pop();
                            break;

                        case 3:
                            displayStack();
                            break;

                        case 4:
                            break;

                        default:
                            printf("Invalid choice!\n");
                    }

                } while (stackChoice != 4);

                break;
            }

            case 2:
            {
                int queueChoice;

                do
                {
                    printf("\n------ QUEUE MENU ------\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Display Queue\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &queueChoice);

                    switch (queueChoice)
                    {
                        case 1:
                            enqueue();
                            break;

                        case 2:
                            dequeue();
                            break;

                        case 3:
                            displayQueue();
                            break;

                        case 4:
                            break;

                        default:
                            printf("Invalid choice!\n");
                    }

                } while (queueChoice != 4);

                break;
            }

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}
/*Problem Statement: Write a menu driven c program to implement the following in a single linked list:
a. Insert a new node at the beginning 
b. Insert a new node at any position
c. Insert a new node at the end
d. Delete a node from the beginning
e. Delete a node from any position
f. Delete a node from the end 
g. Display the list*/

//Source Code:

#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertBeginning()
{
    struct Node *newNode;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the element: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at the beginning.\n");
}

// Insert at any position
void insertPosition()
{
    struct Node *newNode, *temp;
    int value, pos, i;

    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1)
    {
        insertBeginning();
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the element: ");
    scanf("%d", &value);

    newNode->data = value;

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", pos);
}

// Insert at end
void insertEnd()
{
    struct Node *newNode, *temp;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the element: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted at the end.\n");
}

// Delete from beginning
void deleteBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

// Delete from any position
void deletePosition()
{
    struct Node *temp, *deleteNode;
    int pos, i;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1)
    {
        deleteBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;

    printf("Deleted element: %d\n", deleteNode->data);

    free(deleteNode);
}

// Delete from end
void deleteEnd()
{
    struct Node *temp, *deleteNode;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    // Only one node
    if (head->next == NULL)
    {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    deleteNode = temp->next;
    temp->next = NULL;

    printf("Deleted element: %d\n", deleteNode->data);

    free(deleteNode);
}

// Display list
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n===== SINGLY LINKED LIST MENU =====\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at any position\n");
        printf("3. Insert at end\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from any position\n");
        printf("6. Delete from end\n");
        printf("7. Display list\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertPosition();
                break;

            case 3:
                insertEnd();
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deletePosition();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 8);

    return 0;
}
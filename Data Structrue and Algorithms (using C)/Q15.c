/*Problem Definition: Write a menu driven c program to implement the following operations in a binary

search tree:

a. In-order traversal

b. Pre-order traversal

c. Post-order traversal*/

//Source Code:
#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        printf("Duplicate element not allowed!\n");
    }

    return root;
}

// In-order traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order traversal
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main()
{
    struct Node *root = NULL;
    int choice, value;

    do
    {
        printf("\n===== BINARY SEARCH TREE MENU =====\n");
        printf("1. Insert a node\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &value);

                root = insert(root, value);

                printf("Element inserted successfully.\n");
                break;

            case 2:
                if (root == NULL)
                {
                    printf("Tree is empty!\n");
                }
                else
                {
                    printf("In-order traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL)
                {
                    printf("Tree is empty!\n");
                }
                else
                {
                    printf("Pre-order traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                {
                    printf("Tree is empty!\n");
                }
                else
                {
                    printf("Post-order traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
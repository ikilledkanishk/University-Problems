/*Problem Statement: Write a c program to add two polynomials using linked list.*/
//Source Code:

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int coeff, int exp)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

// Insert a term into the polynomial
struct Node* insertTerm(struct Node *head, int coeff, int exp)
{
    struct Node *newNode, *temp;

    if (coeff == 0)
        return head;

    newNode = createNode(coeff, exp);

    // If list is empty
    if (head == NULL)
    {
        return newNode;
    }

    // Insert at beginning if exponent is greater
    if (exp > head->exp)
    {
        newNode->next = head;
        return newNode;
    }

    // If same exponent as first node
    if (exp == head->exp)
    {
        head->coeff += coeff;
        free(newNode);
        return head;
    }

    temp = head;

    while (temp->next != NULL && temp->next->exp > exp)
    {
        temp = temp->next;
    }

    // Same exponent found
    if (temp->next != NULL && temp->next->exp == exp)
    {
        temp->next->coeff += coeff;
        free(newNode);
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

// Create polynomial
struct Node* createPolynomial()
{
    struct Node *head = NULL;
    int n, coeff, exp, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);

        head = insertTerm(head, coeff, exp);
    }

    return head;
}

// Add two polynomials
struct Node* addPolynomials(struct Node *p1, struct Node *p2)
{
    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            result = insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            result = insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            result = insertTerm(result,
                                p1->coeff + p2->coeff,
                                p1->exp);

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Copy remaining terms of first polynomial
    while (p1 != NULL)
    {
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // Copy remaining terms of second polynomial
    while (p2 != NULL)
    {
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return 0;
}

//Problem Statement: Write a c program to evaluate a postfix expression using stack.

//Source Code:
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int i, a, b, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        // If operand, push it onto the stack
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }

        // If operator, pop two operands and perform operation
        else
        {
            b = pop();
            a = pop();

            switch (postfix[i])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;

                case '^':
                    result = (int)pow(a, b);
                    break;

                default:
                    printf("Invalid operator!\n");
                    return 1;
            }

            push(result);
        }
    }

    result = pop();

    printf("Result = %d\n", result);

    return 0;
}
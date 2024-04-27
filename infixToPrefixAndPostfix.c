#include <stdio.h>
#include <stdlib.h>
#define MAX 20

char stk[20];
int top = -1;

void push(char oper)
{
    if (top == MAX - 1)
        printf("Stack Full!!!!");

    else
    {
        top++;
        stk[top] = oper;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack is Empty");
        return -1;
    }

    char ch = stk[top];
    top--;
    return (ch);
}

int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

int covertInfixToPostfix(char exp[], char out[])
{
    int i, j;

    for (i = 0, j = -1; exp[i] != '\0'; i++)
    {
        if (checkIfOperand(exp[i]))
            out[++j] = exp[i];

        else if (exp[i] == '(')
            push('(');

        else if (exp[i] == ')')
        {
            while (top >= 0 && stk[top] != '(')
                out[++j] = pop();
            if (top >= 0 && stk[top] != '(')
                return -1; // invalid expression
            else
                pop();
        }
        else // if an opertor
        {
            while (top >= 0 && precedence(exp[i]) <= precedence(stk[top]))
                out[++j] = pop();
            push(exp[i]);
        }
    }

    while (top >= 0)
        out[++j] = pop();

    out[++j] = '\0';
    // printf("%s", expression);
}
/***********************************************************************************/
int isFull()
{
    return top == MAX - 1;
}

// checking is stack is empty
int isEmpty()
{
    return top == -1;
}



// Function to remove an item from stack.  It decreases top by 1


// Function to return the top from stack without removing it
int peek()
{
    if (isEmpty())
        return INT_MIN;
    return stk[top];
}

// A utility function to check if the given character is operand


// Fucntion to compare precedence
// If we return larger value means higher precedence

// The driver function for infix to postfix conversion
int getPostfix(char *expression)
{
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i)
    {

        if (checkIfOperand(expression[i]))
            expression[++j] = expression[i];

        else if (expression[i] == '(')
            push(expression[i]);

        else if (expression[i] == ')')
        {
            while (!isEmpty(stk) && peek(stk) != '(')
                expression[++j] = pop(stk);
            if (!isEmpty(stk) && peek(stk) != '(')
                return -1; // invalid expression
            else
                pop(stk);
        }
        else // if an opertor
        {
            while (!isEmpty(stk) && precedence(expression[i]) <= precedence(peek(stk)))
                expression[++j] = pop(stk);
            push(expression[i]);
        }
    }

    // Once all inital expression characters are traversed
    // adding all left elements from stack to exp
    while (!isEmpty(stk))
        expression[++j] = pop(stk);

    expression[++j] = '\0';
}

void reverse(char *exp)
{

    int size = strlen(exp);
    int j = size, i = 0;
    char temp[size];

    temp[j--] = '\0';
    while (exp[i] != '\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp, temp);
}

void brackets(char *exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
        i++;
    }
}
void InfixtoPrefix(char *exp)
{

    int size = strlen(exp);

    // reverse string
    reverse(exp);
    // change brackets
    brackets(exp);
    // get postfix
    getPostfix(exp);
    // reverse string again
    reverse(exp);
}


/***********************************************************************************/

int main()
{
    char expression[] = "((p+(q*r))-s)";
    char output[MAX] = {'\0'};
    covertInfixToPostfix(expression, output);
    printf("%s %s\n", expression, output);


    printf("The infix is: ");
    char expression2[] = "((a/b)+c)-(d+(e*f))";
    printf("%s\n", expression2);
    InfixtoPrefix(expression2);

    printf("The prefix is: ");
    printf("%s\n", expression2);
    return 0;
}

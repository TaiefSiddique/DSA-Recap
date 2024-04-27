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

int main()
{
    char expression[] = "((p+(q*r))-s)";
    char output[MAX] = {'\0'};
    covertInfixToPostfix(expression, output);
    printf("%s %s\n", expression, output);
    return 0;
}
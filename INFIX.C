#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPRESSION_SIZE 100

char stack[MAX_STACK_SIZE];
int top = -1;

void push(char operator)
{
    if (top == MAX_STACK_SIZE - 1)
    {
	printf("Stack overflow\n");
	exit(0);
    }
    else
    {
	stack[++top] = operator;
    }
}

char pop()
{
    if (top == -1)
    {
	printf("Stack underflow\n");
	exit(0);
    }
    else
    {
	return stack[top--];
    }
return 0;
}

int priority(char operator)
{
    switch (operator)
    {
	case '^':
	    return 3;
	case '*':
	case '/':
	    return 2;
	case '+':
	case '-':
	    return 1;
	default:
	    return 0;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j;
    i = j = 0;

    for (i = 0; infix[i] != '\0'; i++)
    {
	if (infix[i] >= 'a' && infix[i] <= 'z')
	{
	    postfix[j++] = infix[i];
	}
	else if (infix[i] == '(')
	{
	    push(infix[i]);
	}
	else if (infix[i] == ')')
	{
	    while (stack[top] != '(')
	    {
		postfix[j++] = pop();
	    }
	    pop();
	}
	else
	{
	    while (priority(stack[top]) >= priority(infix[i]))
	    {
		postfix[j++] = pop();
	    }
	    push(infix[i]);
	}
    }

    while (top != -1)
    {
	postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void main()
{
    char infix[MAX_EXPRESSION_SIZE];
    char postfix[MAX_EXPRESSION_SIZE];
    clrscr();

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    getch();
}
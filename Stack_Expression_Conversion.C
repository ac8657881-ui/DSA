#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char stack[100];
int top = -1;
void push(char x)    // Push
{
    stack[++top] = x;
}
char pop()    // Pop
{
    return stack[top--];
}
int priority(char x)      // Priority of operators
{
    if(x == '^')
        return 3;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else
        return 0;
}                          
void infixToPostfix(char infix[])      // Infix to Postfix
{
    char postfix[100];
    int i = 0, j = 0;
    char x;
    while(infix[i] != '\0')
    { 
        if(isalnum(infix[i]))      // Operand
        {
            postfix[j++] = infix[i];
        }                                  
        else if(infix[i] == '(')       //Opening bracket
        {
            push(infix[i]);
        }
        // Closing bracket
        else if(infix[i] == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // remove//
        }
        else
        {
            while(top != -1 &&
                  priority(stack[top]) >= priority(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while(top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}
int main()
{
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
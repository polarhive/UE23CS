// Write a C program that reads an expression (containing parentheses) as the input.
// Program should determine whether the expression has balanced parentheses. i.e., for each opening parenthesis '(' there should be a corresponding closing parenthesis ')' in the
// correct order.
// Print appropriate message.
// Use a function isValidParenthesis() to check the expression is balanced or not. (NOTE:
// Don’t use any String built-in functions).

#include <stdio.h>
int isValidParenthesis(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            count++;
        }
        else if (str[i] == ')')
        {
            count--;
            if (count < 0)
                return 0; // Not balanced
        }
    }
    return count == 0;
}
int main()
{
    char expression[100];
    scanf("%s", expression);

    if (isValidParenthesis(expression))
        printf("Balanced");
    else
        printf("Not balanced");
    return 0;
}
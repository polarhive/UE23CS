// Write a C Program to read a string contain only brackets such as { , }, (, ), [, ]
// Check if the string is balanced or not. The input string is balanced if open brackets and
// closed brackets are same type of brackets and in the balanced order. (NOTE: Don’t use
// any String built-in functions).

#include <stdio.h>
#include <string.h>

int balance_brackets(char str[])
{
    int ctr = 0, x = 0, y = 0, z = 0, i = 0;
    char stack[100];
    while (str[i] != 0)
    {
        // Checking for opening brackets and storing them in the temporary stack
        if (str[i] == '(')
        {
            x++;
            stack[++ctr] = 1; // Storing the value 1 for '(' in the stack
        }
        if (str[i] == '[')
        {
            y++;
            stack[++ctr] = 2; // Storing the value 2 for '[' in the stack
        }
        if (str[i] == '{')
        {
            z++;
            stack[++ctr] = 3; // Storing the value 3 for '{' in the stack
        }
        // Checking for closing brackets and validating them against the stack content
        if (str[i] == ')')
        {
            if (stack[ctr] == 1)
            {
                x--;
                ctr--;
            }

            else
            {
                return 0;
            }
        }
        if (str[i] == ']')
        {
            if (stack[ctr] == 2)
            {
                y--;
                ctr--;
            }
            else
            {
                return 0;
            }
        }
        if (str[i] == '}')
        {
            if (stack[ctr] == 3)
            {
                z--;
                ctr--;
            }
            else
            {
                return 0;
            }
        }
        i++;
    }
    // Checking if all brackets are balanced
    if (x > 0 || y > 0 || z > 0)
        return 0;
    return 1;
}
int main()
{
    char str[20];
    scanf("%s", str);
    printf("Balanced = %d", balance_brackets(str));
    return 0;
}
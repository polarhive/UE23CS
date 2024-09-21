#include <stdio.h>

// Function prototypes
void push(char *s, int *, char);
char pop(char *s, int *);
int isempty(int);
int match(char *);

int main()
{
  char expr[10]; // Array to store the expression
  printf("Enter the expression\n");
  scanf("%s", expr); // Read the expression from the user
  int result = match(expr); // Check if the parentheses match
  if (result)
    printf("Matching of parenthesis succeeds\n");
  else
    printf("Matching fails\n");
}

// Function to check if the parentheses match
int match(char *expr)
{
  int i = 0;
  char s[10]; // Stack to store the parentheses
  int top = -1; // Initialize top of stack
  while (expr[i] != '\0')
  {
    char x;
    char ch = expr[i];
    switch (ch)
    {
    case '(':
    case '{':
    case '[':
      push(s, &top, ch); // Push opening parentheses onto the stack
      break;
    case ')':
      if (!isempty(top)) // If stack is not empty
      {
        x = pop(s, &top); // Pop from stack
        if (x == '(')
          break;
        else
          return 0; // Mismatch of parentheses
      }
      else
        return 0; // Extra closing parenthesis
    case '}':
      if (!isempty(top)) // If stack is not empty
      {
        x = pop(s, &top); // Pop from stack
        if (x == '{')
          break;
        else
          return 0; // Mismatch of parentheses
      }
      else
        return 0; // Extra closing parenthesis

    case ']':
      if (!isempty(top)) // If stack is not empty
      {
        x = pop(s, &top); // Pop from stack
        if (x == '[')
          break;
        else
          return 0; // Mismatch of parentheses
      }
      else
        return 0; // Extra closing parenthesis

    } // End switch
    i++;
  } // End while
  if (isempty(top))
    return 1; // All parentheses matched
  return 0; // Extra opening parenthesis
}

// Function to check if the stack is empty
int isempty(int top)
{
  if (top == -1)
    return 1;
  return 0;
}

// Function to push an element onto the stack
void push(char *s, int *t, char x)
{
  ++*t; // Increment top
  s[*t] = x;
}

// Function to pop an element from the stack
char pop(char *s, int *t)
{
  char x;
  x = s[*t];
  --*t; // Decrement top
  return x;
}

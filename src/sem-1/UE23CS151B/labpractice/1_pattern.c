#include <stdio.h>
int main()
{
    int rows, spaces, j;
    // Prompt the user to enter the number of rows
    scanf("%d", &rows);
    if (rows <= 0)
    {
        printf("Invalid input");
        return 1;
    }
    // Loop to iterate over each row
    for (int i = 1; i <= rows; i++)
    {
        // Loop to print spaces
        for (spaces = 1; spaces <= rows - i; spaces++)
        {
            printf(" "); // Two spaces for alignment
        }
        // Loop to print increasing numbers
        for (j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        // Loop to print decreasing numbers
        for (j = i - 1; j >= 1; j--)
        {
            printf("%d ", j);
        }
        // Move to the next line for the next row
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
int main()
{
    int rows, i, j, space;
    // Accepting user input for the number of rows
    scanf("%d", &rows);
    // Loop to iterate through each row
    for (i = 1; i <= rows; i++)
    {
        // Loop to add spaces before asterisks
        for (space = 1; space <= rows - i; space++)
            printf(" ");
        // Loop to print asterisks
        for (j = 1; j <= 2 * i - 1; j++)
            printf("*");
        // Move to the next line after each row
        printf("\n");
    }
    return 0;
}
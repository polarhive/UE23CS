#include<stdio.h>
int main()
{
    int a,b;
    a=16;b=78;
    float c=2.5;
    printf("%d %d\n", sizeof(a), sizeof(short int));
    printf("%4.2f\n",c);
    printf("%2.1f\n",c);
    printf("%-5d %d\n",16,b); // This line prints the value of a left-aligned in a field of width 5, and the value of b.
    printf("ravan\rram\n"); //This line prints "ravan", then moves the cursor to the beginning of the line and overwrites "ravan" with "ram".
    printf("ram\nlakhan\n"); //This line prints "ram" followed by a new line, and then "lakhan" on a new line.
    printf("\"Mahabharat\""); //This line prints the string "Mahabharat" enclosed in double quotes.
    return 0;
}

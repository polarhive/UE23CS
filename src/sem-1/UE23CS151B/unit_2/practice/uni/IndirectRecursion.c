/* C program to show -- indirect recursion
   print numbers from 1 to 10 in such a manner that when an odd no is encountered,
   we will print that number plus 1. When an even number is encountered, we would
   print that number minus 1 and will increment the current number at every step.
*/

#include <stdio.h>
void odd();
void even();
int n = 1;

void odd()
{
    if (n <= 10)
    {
        printf("%d ", n + 1);
        n++;
        even();
    }
    return;
}

void even()
{
    if (n <= 10)
    {
        printf("%d ", n - 1);
        n++;
        odd();
    }
    return;
}

int main(void)
{
    odd();
    return 0;
}

#include <stdio.h>
int main()
{
    int n, first = 0, second = 1, next;
    scanf("%d", &n);
    while (first <= n)
    {
        if (first % 2 == 0)
        {
            printf("%d ", first);
        }
        next = first + second;
        first = second;
        second = next;
    }
    return 0;
}
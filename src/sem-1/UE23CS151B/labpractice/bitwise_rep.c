#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int count = 0;
    for (int i = 0; i < 16; i++)
    {
        if (n & (1 << i))
            count++;
    }
    printf("%d", count);
    return 0;
}
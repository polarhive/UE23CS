#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < sqrt(n); i++)
        if (n % i == 0)
            printf("%d %d\n", i, n / i);
    return 0;
}

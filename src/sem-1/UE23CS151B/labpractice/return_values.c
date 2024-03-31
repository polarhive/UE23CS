#include <stdio.h>
int main()
{
    int n;
    int scanfReturnValue = scanf("%d", &n);
    printf("Return value of Input function: %d\n", scanfReturnValue);
    printf("Return value of Output function: %d\n", printf("Number=%d", n));
    return 0;
}
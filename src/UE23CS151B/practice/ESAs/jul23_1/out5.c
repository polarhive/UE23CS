#include <stdio.h>
int main()
{
    int i = 333;
    int j = 666;
    int *const p = &i;
    *p = 555;
    printf("%d\n", *p);
}

#include <stdio.h>
int main()
{
    int a[15] = {[2] = 29, [9] = 3};
    for (int i; i < 15; i++) printf("%d\n", a[i]);
}

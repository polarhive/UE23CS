#include <stdio.h>
#define MAX 5
#define fun(a, b) a *b
int main()
{
    printf("%d\t", fun(MAX, 3 + 6));
#undef MAX
    int MAX = 35;
    printf("%d\t", MAX);
#define MAX 22
    printf("%d", MAX);
}

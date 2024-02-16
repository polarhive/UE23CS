#include<stdio.h>
int main()
{
    int i;
    printf("Input a number to find even/odd: ");
    scanf("%d", &i);
    if (i % 2 == 0) printf("%s", "yes\n");
    else printf("%s", "no\n");
    return 0;
}

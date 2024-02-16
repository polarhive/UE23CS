#include<stdio.h>
int main()
{
    int i;
    printf("Input a number to divide by 13: ");
    scanf("%d", &i);
    if (i % 13 == 0) printf("%s", "yes\n");
    else printf("%s", "no\n");
    return 0;
}

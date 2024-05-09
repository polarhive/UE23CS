#include<stdio.h>
int main()
{
    int i,j,n;
    char c='A';
    printf("How Many Lines \nYou Want to Print: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%c ",c);
        }
        c++;
        printf("\n");
    }
    return 0;
}

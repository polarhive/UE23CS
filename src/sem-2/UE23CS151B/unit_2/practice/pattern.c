#include<stdio.h>
int main()
{
    int i,a,b;
    for(a=4, b=1; b<=4; a--, b++ ) // Here, a>=1 or b<=4 condition is optional. Both the
         {
        for(i=1;i<a;i++)
            printf(" ");
        for(i=1;i<=b;i++)
            printf("* ");
        printf("\n");
}
return 0;
}

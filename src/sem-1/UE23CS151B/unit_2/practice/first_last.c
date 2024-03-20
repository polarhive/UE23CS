#include<stdio.h>
int main()
{
    int s=0,l;
    long n;
    printf("Enter Number : ");
    scanf("%ld",&n);
    if(n>10)
    {
        l=n%10;
    }
    while(n>=10) n=n/10;
    s=l+n;
    printf("\nFirst Digit : %ld \nLast Digit : %d\n",n,l);
    printf("\n\nSum of First and Last Digit : %d\n",s);
    return 0;
}

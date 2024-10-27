#include<stdio.h>
int main()
{
    int n = 826;
    int sum = 0;
    do
    {
        for (sum=0; n; n/=10)
        {
            sum+=n%10;
        }
        n=sum;
    } 
    while(sum>9);
    printf("The digital root is %d\n", sum);
    return 0;
}


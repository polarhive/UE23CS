#include <stdio.h>
int main()
{
    int n;
    printf("enter no: ");
    scanf("%d",&n);
    //n&1 actually results in 0000000d where d is your LSB
    if(n&1==1) printf("it's odd no");//for odd no LSB 1
    else printf("it's even no");//for even no LSB 0
    return 0;
}

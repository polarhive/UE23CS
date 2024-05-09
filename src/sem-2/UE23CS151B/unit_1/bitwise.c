#include<stdio.h>
int main()
{
    int n=2;
    printf("%d\n", n<<1); // to multiply an n value by 2
    printf("%d\n", n&1); // to check odd/even

    // to swap 2 variables a and b
    int a=10;
    int b=20;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("%d %d\n", a, b); 

    int i = 1;
    // to check if ith bit in a variable is 1
    printf("%d \n",n);
    n & (1<<i); // 0 implies non set, non 0 implies set
    printf("%d \n",n);

    // to set the ith bit in n
    printf("%d \n",n);
    n = n | 1 << i;
    printf("%d \n",n);

    // to clear the ith bit in n
    printf("%d \n",n);
    n = n & ~(1<<i);
    printf("%d \n",n);
    return 0;
}



#include<stdio.h>
int what(int num,int res)
{
    if(num==0)
        return res;
    else
        return what(num/10,res+(num%10));
}

int main()
{
    int a = 151;
    printf("%d\n",what(a,0));
    return 0;
}

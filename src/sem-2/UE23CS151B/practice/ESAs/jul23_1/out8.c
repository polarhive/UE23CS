#include<stdio.h>
void fun();
int main()
{
    fun();
    fun();
}
void fun()
{
    static int a = -1;
    a--;
    printf("%d\t",a);
}

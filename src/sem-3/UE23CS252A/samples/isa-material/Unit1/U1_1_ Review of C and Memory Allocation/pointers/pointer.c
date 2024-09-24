#include<stdio.h>
main()
{
 int x=10;
 int*y;
 printf("Value of x=%d\n",x);//prints 10
 printf("Address of x = %p\n",&x);//address of x
 y=&x;
printf("The value of x=%d\n",*y);//print 10(value of x)
printf("The value of x=%d\n",*(&x));//10(value of x)
printf("the value of y=%p\n",&y);
}

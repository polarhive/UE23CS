#include<stdio.h>
void swap(int*, int*);
main()
{
 int a,b;
 a=10;
 b=20;
 printf("Before swap a=%d b=%d\n",a,b);
 swap(&a,&b);
 printf("After swap a=%d b=%d\n",a,b);
}

 void swap(int *a, int *b)
 {
   int t;
   t=*a;
   *a=*b;
  *b=t;
 }

#include<stdio.h>
#define sqr1(x) x*x
#define sqr2(y) (y)*(y)

int main()
{
	printf("%d ",sqr1(2+2));
	printf("%d\n",sqr2(2+3));
	return 0;
}

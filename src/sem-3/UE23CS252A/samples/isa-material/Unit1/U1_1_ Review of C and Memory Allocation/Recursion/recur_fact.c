#include<stdio.h>

int factorial(int);

int main()
{
	int n;
	scanf("%d",&n);
	
	int res=factorial(n);
	
	printf("%d!=%d\n",n,res);
}

int factorial(int n)
{
	if(n==0)
		return 1;
	else
		return n*factorial(n-1);
}
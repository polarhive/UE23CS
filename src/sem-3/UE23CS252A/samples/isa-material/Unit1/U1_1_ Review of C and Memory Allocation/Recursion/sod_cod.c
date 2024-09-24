#include<stdio.h>

int sod(int n);
int cod(int n);
int main()
{
	int n;
	printf("Enter a positive integer\n");
	scanf("%d",&n);
	
	int res1=sod(n);
	int res2=cod(n);
	
	printf("Sum and count of digits of %d is %d,%d respectively\n",n,res1,res2);
}

int sod(int n)
{
	if(n==0)
		return 0;
	else
		return (n%10)+sod(n/10);
}
int cod(int n)
{
	if(n==0)
		return 0;
	else
		return 1+cod(n/10);
}
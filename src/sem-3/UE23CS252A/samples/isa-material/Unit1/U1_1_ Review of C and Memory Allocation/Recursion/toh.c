#include<stdio.h>

void ToH(int n,char src,char aux,char dest);

int main()
{
	int n;
	
	printf("Enter the no. of disks\n");
	scanf("%d",&n);
	
	ToH(n,'A','B','C');
}

void ToH(int n,char src,char aux,char dest)
{
	if(n==1)
		printf("Mov disk %d from %c to %c\n",n,src,dest);
	else
	{
		ToH(n-1,src,dest,aux);
		printf("Mov disk %d from %c to %c\n",n,src,dest);
		ToH(n-1,aux,src,dest);
	}
}
/*#include<stdio.h>
#include<stdlib.h>
int main()
{
	/*
	//malloc
	int *p=(int *)malloc(sizeof(int));
	*p=10;
	printf("p=%d\n",*p);
	
	//int *x;
	int n,i;
	printf("enter no of elements\n");
	scanf("%d",&n);
	int *x=(int *)malloc(n*sizeof(int));
	
	if(x==NULL)
		printf("memory not allocated\n");
	else
	{
		for(i=0;i<n;i++)
			printf("%d",*(x+i));
		printf("memory successfully allocated\n");
		printf("enter the integer values");
		for(i=0;i<n;i++)
			scanf("%d",x+i);
		printf("output\n");
		
		for(i=0;i<n;i++)
			printf("%d",*(x+i));
	}
	free(x);
	for(i=0;i<n;i++)
			printf("%d",*(x+i));
	
	return 0;

}


//calloc

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	printf("enter no of elements\n");
	scanf("%d",&n);
	int *x=(int *)calloc(n,sizeof(int));
	
	if(x==NULL)
		printf("memory not allocated\n");
	else
	{
		printf("before realloc ptr is %p\n",x);
		for(i=0;i<n;i++)
			printf("%d",*(x+i));
		printf("memory successfully allocated\n");
		printf("enter the integer values");
		for(i=0;i<n;i++)
			scanf("%d",x+i);
		printf("output\n");
		
		for(i=0;i<n;i++)
			printf("%d",*(x+i));
	}
	
	//realloc
	printf("enter new size\n");
	int ns;
	scanf("%d",&ns);
	
	 x=(int *)realloc(x,ns*sizeof(int));
	
	if(x==NULL)
		printf("cannot allocate");
	else
	{
		printf("after realloc ptr is %p\n",x);
		printf("after realloc\n");
		for(i=0;i<ns;i++)
			printf("%d\n",*(x+i));
	}
	return 0;

}
*/
//free
//DMA Error

#include<stdio.h>
#include<stdlib.h>
int main()
{
	
	//malloc
	int *p=(int *)malloc(sizeof(int));
	*p=10;
	printf("p=%d\n",*p);
	free(p);
	p=NULL;
	free(p);
	printf("p=%d\n",*p);
	
	 *p=(int *)malloc(sizeof(int));
	*p=100;
	printf("p=%d\n",*p);
	return 0;
}	







#include<stdlib.h>
#include<stdio.h>

int qinsert(int,int*,int*,int*,int);
int qdelete(int *,int *, int*);
void display(int *,int,int);

int main()
{
	int *q;
	int ch,k,x;
	int f,r, size;
	f=r=-1;
	printf("Enter the size of the queue..");
	scanf("%d",&size);

	q=(int*)malloc(sizeof(int)*size);
	while(1)
	{
		display(q,f,r);
		printf("\n1..Insert");
		printf("\n2..Delete");
		printf("\n3..display");
		printf("\n4..EXIT");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the value..");
					scanf("%d",&x);
					k=qinsert(x,q,&f,&r,size);
					if(k>=0)
						printf("Element inserted successfully\n");
					break;
			case 2:	k=qdelete(q,&f,&r);
					if(k>=0)
						printf("element deleted=%d\n",k);
					break;
			case 4:	exit(0); 
		}
	}
}

int qinsert(int x, int *q, int *f, int *r, int size)
{
	//check for queue full
	if(*r==size-1)
	{
		printf("Queue full ..Cannot insert\n");
	    return -1;
	}
	(*r)++;  // ++*r;  increment the rear
	q[*r]=x;
	if(*f==-1)  // if first element
		*f=0;
	return 1;
}
	
	
int qdelete(int *q, int *f, int *r)
{
	int x;
	//check if the queue is empty
	if(*f==-1)
	{
		printf("Empty Queue..\n");
		return -1;
	}
	x= q[*f];
	if(*f==*r) // only one element 
		*f=*r=-1;
	else
		(*f)++;  // increment the front after deletion
	return x;
}
		
void display(int *q, int f, int r)
{
	int i;
	if(f==-1)
		printf("Queue empty..\n");
	else
	{
		for(i=f;i<=r;i++)
			printf("%d ",q[i]);
	}
	printf("\n");
}
		
		
		
#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int *item;
	int f,r,size;
};

typedef struct queue  queue_t;

int qinsert(queue_t *,int);
int qdelete(queue_t*);
void display(queue_t*);
void init(queue_t*);

int main()
{
	queue_t q;
	int ch,k,x;
	init(&q);
	while(1)
	{
		printf("\n\n1..Insert");
		printf("\n2..Delete");
		printf("\n3..display");
		printf("\n4..EXIT\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("\nEnter the value:\t");
					scanf("%d",&x);
					k=qinsert(&q,x);
					if(k>=0)
						printf("Element inserted successfully\n");
					break;
			case 2:	k=qdelete(&q);
					if(k>=0)
					printf("element deleted=%d\n",k);
					break;
			case 3:	display(&q);
		            break;
			case 4:	exit(0); 
		}
	}
}

void init(queue_t *ptr_q)
{
	printf("Enter the max size of the queue:\t");
	scanf("%d",&ptr_q->size);
	ptr_q->item=(int*)malloc(sizeof(int)*ptr_q->size);
	ptr_q->f=ptr_q->r=-1;
}

int qinsert(queue_t *ptr_q, int data)
{
	//check for queue full
	if(ptr_q->r==ptr_q->size-1)
	{
		printf("\nQueue full...cannot insert");
		return -1;
	}
	//increment rear 
	ptr_q->r++;
	 
	ptr_q->item[ptr_q->r]=data;
	if(ptr_q->f==-1) //first element
		ptr_q->f=0;
    return 1;
}

int qdelete(queue_t *ptr_q)
{
	int x;
	//check if queue is empty
	if(ptr_q->f==-1)
	{
		printf("Empty queue..cannot delete");
		return -1;
	}
	x=ptr_q->item[ptr_q->f]; //get the first element
	//if only one element in queue
	if(ptr_q->f==ptr_q->r)
		ptr_q->f=ptr_q->r=-1;
	else
		ptr_q->f++;
	return x;
}

void display(queue_t *ptr_q)
{
	int i;
    if(ptr_q->f==-1)
		printf("\n Empty queue..");
	else
	{
		printf("\nElements in the queue are:\n");
		for(i=ptr_q->f ;i<=ptr_q->r;i++)
		printf("%d\t",ptr_q->item[i]);
	}
}
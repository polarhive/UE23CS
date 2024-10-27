#include<stdlib.h>
#include<stdio.h>

struct queue
{
	int *cq;
	int f,r,size;
};

typedef struct queue queue_t;

void init(queue_t*);
int qinsert(queue_t*,int);
int qdelete(queue_t*);
void display(queue_t*);
int qisempty(queue_t*);

int main()
{
	int ch,k,x;
	queue_t q;
	init(&q);
	while(1)
	{
		//display(&q);
		printf("\n1..Insert");
		printf("\n2..Delete");
		printf("\n3..Display");
		printf("\n4..EXIT");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the value..");
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

 
 int qisempty(queue_t *ptr_q)
 {
	 if(ptr_q->f==-1)
		 return 1;
	 return 0;
 }

 void init(queue_t *ptr_q)
 {
    printf("Enter the size of queue..\n");
    scanf("%d",&ptr_q->size);
    ptr_q->f=ptr_q->r=-1;
    ptr_q->cq=(int*)malloc(sizeof(int)*(ptr_q->size));
 }	
	 
 int qinsert (queue_t *ptr_q, int key)
 {
	 if((ptr_q->r+1)%ptr_q->size==ptr_q->f)
	 {
		 printf("queue full.. cannot insert\n");
		 return -1;
	 }
	 ptr_q->r=(ptr_q->r+1)%ptr_q->size; //increment rear 
	 ptr_q->cq[ptr_q->r]=key; // insert the element
	 if(ptr_q->f==-1) //if first element
		 ptr_q->f=0;
	 return 1;
 }
 
 int qdelete(queue_t *ptr_q)
 {
	 int key;
	 if(ptr_q->f==-1)
	 {
		 printf("Empty queue..\n");
		 return -1;
	 }
	 key=ptr_q->cq[ptr_q->f];
	 if(ptr_q->f==ptr_q->r)//only one element
	    ptr_q->f=ptr_q->r=-1;
	 else
		 ptr_q->f=(ptr_q->f+1)%ptr_q->size;
	 return key;
 }
		 
	void display(queue_t* ptr_q)
	{
		int f,r,size;
		if(ptr_q->f==-1)
			printf("Queue empty..\n");
		 else
		 {
			 f=ptr_q->f;
			 r=ptr_q->r;
			 size=ptr_q->size;
			 while(f!=r)
			 {
				 printf("%d ",ptr_q->cq[f]);
				 f=(f+1)%size;
			 }
			printf("%d ",ptr_q->cq[f]);
		 }	
	}		 
			 
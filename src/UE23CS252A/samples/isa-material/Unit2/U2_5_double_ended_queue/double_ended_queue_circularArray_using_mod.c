//Double Ended Queue using Circular Array
#include<stdio.h>
#define MAX 5
typedef struct queue
{
	int q[MAX];
	int front;
	int rear;
}QUEUE;

void initQueue(QUEUE *pq);
int isEmpty(QUEUE *pq);
int isFull(QUEUE *pq);
//Precondition: Queue is not full
void enqueRear(QUEUE *pq,int ele);
//Precondition: Queue is not empty
int dequeueFront(QUEUE *pq);
void display(QUEUE *pq);
//Precondition: Queue is not full
void enqueFront(QUEUE *pq,int ele);
//Precondition: Queue is not empty
int dequeueRear(QUEUE *pq);

int main()
{
	QUEUE qobj;
	initQueue(&qobj);
	
	int choice,ele;
	
	printf("1.EnqRear 2.DeqFront 3.Display 4.EnqFront 5.DeqRear\n");
	scanf("%d",&choice);
	
	do
	{
		switch(choice)
		{
			case 1:if(isFull(&qobj))
						printf("Queue is already full\n");
					else
					{
						printf("Enter an integer\n");
						scanf("%d",&ele);
						enqueRear(&qobj,ele);
					}
					break;
			case 2:if(isEmpty(&qobj))
					printf("Queue is already empty\n");
					else
					{
						ele=dequeueFront(&qobj);
						printf("Dequed %d\n",ele);
					}
					break;
			case 3:display(&qobj);
					break;
			case 4:if(isFull(&qobj))
						printf("Queue is already full\n");
					else
					{
						printf("Enter an integer\n");
						scanf("%d",&ele);
						enqueFront(&qobj,ele);
					}
					break;
			case 5:if(isEmpty(&qobj))
					printf("Queue is already empty\n");
					else
					{
						ele=dequeueRear(&qobj);
						printf("Dequed %d\n",ele);
					}
					break;
		}
		printf("1.EnqRear 2.DeqFront 3.Display 4.EnqFront 5.DeqRear\n");
		scanf("%d",&choice);
	}while(choice<6);
}

void initQueue(QUEUE *pq)
{
	pq->front=-1;
	pq->rear=-1;
}

int isEmpty(QUEUE *pq)
{
	return pq->front==-1;		//return pq->rear==-1;
}

int isFull(QUEUE *pq)
{
	return (pq->rear+1)%MAX == pq->front;
}

//Precondition: Queue is not full
void enqueRear(QUEUE *pq,int ele)
{
	if(isEmpty(pq))
	{
		pq->front=0;
		pq->rear=0;
		pq->q[0]=ele;	//pq->q[pq->rear]=ele
	}
	else
	{
		pq->rear=(pq->rear+1)%MAX;
		pq->q[pq->rear]=ele;
	}
}
//Precondition: Queue is not empty
int dequeueFront(QUEUE *pq)
{
	int ele=pq->q[pq->front];
	if(pq->front == pq->rear)	//Single element case
	{
		initQueue(pq);
	}
	else
	{
		pq->front=(pq->front+1)%MAX;
	}
	return ele;
}
void display(QUEUE *pq)
{
	if(isEmpty(pq))
		printf("Empty Queue\n");
	else
	{
		int i;
		for(i=pq->front;i!=pq->rear;i=(i+1)%MAX)
			printf("%d ",pq->q[i]);
		printf("%d\n",pq->q[i]);
	}
}

//Precondition: Queue is not full
void enqueFront(QUEUE *pq,int ele)
{
	if(isEmpty(pq))
	{
		pq->front=0;
		pq->rear=0;
		pq->q[0]=ele;
	}
	else
	{
		pq->front=(pq->front-1+MAX)%MAX;
		pq->q[pq->front]=ele;
	}
}
//Precondition: Queue is not empty
int dequeueRear(QUEUE *pq)
{
	int ele=pq->q[pq->rear];
	if(pq->front==pq->rear)
	{
		initQueue(pq);
	}
	else
	{
		pq->rear=(pq->rear-1+MAX)%MAX;
	}
	return ele;
}
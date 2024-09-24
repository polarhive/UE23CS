/*program to implement double ended queue */
#include<stdlib.h>
#include<stdio.h>
struct node
{
	int key;
	struct node *next,*prev;
};

typedef struct node node_t;

struct dequeue
{
	node_t *front;
	node_t *rear;
};

typedef struct dequeue dequeue_t ;

void qdisplay(dequeue_t*);
void qinsert_head(dequeue_t*,int);
void qinsert_tail(dequeue_t*, int);
int qdelete_head(dequeue_t*);
int qdelete_tail(dequeue_t*);
void init( dequeue_t *p);
int main()
{
	int k,x,ch;
	dequeue_t dq; 
	init(&dq);
  
	while(1)
	{
		//qdisplay(&dq);
		printf("\n1..insert head");
		printf("\n2..insert Tail");
		printf("\n3..Delete Head");
		printf("\n4..Delete Tail");
		printf("\n5..display");
		printf("\n6..EXIT");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the value..");
					scanf("%d",&x);
					qinsert_head(&dq,x);
					break;
			case 2:	printf("Enter the value..");
					scanf("%d",&x);
					qinsert_tail(&dq,x);      
					break;
			case 3:	k=qdelete_head(&dq);
					if(k>=0)
						printf("Element deleted = %d\n",k);
					break;
			case 4:	k=qdelete_tail(&dq);
					if(k>=0)
						printf("Element deleted = %d\n",k);
					break;
			case 5:	qdisplay(&dq); 
		             break;
			case 6:	exit(0);
		}
	}
}

void init( dequeue_t *p)
{
	p->front=p->rear=NULL;
}

int  qdelete_tail(dequeue_t *p)
{
	node_t *pres;
	int key;
	pres=p->rear;
	key=pres->key; 
		   
	if(p->front==p->rear)
		p->front=p->rear=NULL;
	else
	{
		p->rear=pres->prev;
		p->rear->next=NULL;
	}
	free(pres);
	return key;
}
		   		   
int qdelete_head(dequeue_t *p)
{
	node_t *pres;
	int key;
	pres=p->front;
	key=pres->key;
		   
	//only one node
	if(p->front==p->rear)
		p->front=p->rear=NULL;
	else
	{
		p->front=pres->next;
		p->front->prev=NULL;
	}
		free(pres);
		return key;
}
		  
void  qinsert_tail(dequeue_t *p ,int x)
{
	node_t *temp;		 
	//create a node
	temp=(node_t*)malloc(sizeof(node_t));
	temp->key=x;
	temp->next=temp->prev=NULL;
	if(p->front==NULL)
		p->front=p->rear=temp;
	else
	{
		p->rear->next=temp;
		temp->prev=p->rear;
		p->rear=temp;
	}
}
	
void  qinsert_head(dequeue_t *p, int x)
{
    node_t *temp;		 
	//create a node
	temp=(node_t*)malloc(sizeof(node_t));
	temp->key=x;
	temp->next=temp->prev=NULL;
	//is this the first node
	if(p->front==NULL)
		p->front=p->rear=temp;
	else //insert in front of the list
	{
		temp->next=p->front;
		p->front->prev=temp;
		p->front=temp;
	}
}
	 	   
void qdisplay(dequeue_t* p)	
{
	node_t *pres;
    if(p->front==NULL)
		printf("Empty Dequeue");
	else
	{
		pres=p->front;
		while(pres!=p->rear)
		{
			printf("%d<->",pres->key);
			pres=pres->next;
		}
		printf("%d",pres->key); //print the last node
	}
}
	  
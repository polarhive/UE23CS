//Ascending priority queue using linked list
//Ordered insertion (O(n)), min deletion (O(1))
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	int priority;
	struct node *next;
}NODE;

void enqueue(NODE **head,int ele,int pri);
void display(NODE *head);
void destroyQueue(NODE **head);
void dequeue(NODE **head,int *ele,int *pri);

int main()
{
	NODE *head=NULL;
	
	enqueue(&head,20,20);
	enqueue(&head,30,30);
	enqueue(&head,25,25);
	enqueue(&head,10,10);
	
//	display(head);
	int ele,pri;
	if(head!=NULL)
	{
		dequeue(&head,&ele,&pri);
		printf("Deqd: info %d,priority %d\n",ele,pri);
	}
	
	if(head!=NULL)
	{
		dequeue(&head,&ele,&pri);
		printf("Deqd: info %d,priority %d\n",ele,pri);
	}
	
//	display(head);
	destroyQueue(&head);
}

NODE* createNode(int ele,int pri)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->priority=pri;
	newNode->next=NULL;
	
	return newNode;
}

void enqueue(NODE **head,int ele,int pri)
{
	NODE *newNode=createNode(ele,pri);
	
	NODE *p=*head;
	NODE *q=NULL;
	
	while(p!=NULL && p->priority < newNode->priority)
	{
		q=p;
		p=p->next;
	}
	if(q==NULL)	//node to be inserted is the first node
	{
		newNode->next=*head;	//newNode->next=p;
		*head=newNode;
	}
	else	//node to be inserted is in middle or at the end
	{
		newNode->next=p;
		q->next=newNode;
	}
}
 
void display(NODE *head)
{
	if(head==NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		NODE *p=head;
		
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
	}
	printf("\n");
} 

void destroyQueue(NODE **head)
{
	NODE *p;
	
	while(*head!=NULL)
	{
		p=*head;
		*head=(*head)->next;
//		printf("%d freed\n",p->info);
		free(p);
	}
}

void dequeue(NODE **head,int *ele,int *pri)
{
	NODE *p=*head;
	*ele=p->info;
	*pri=p->priority;
	
	*head=(*head)->next;
	free(p);
}
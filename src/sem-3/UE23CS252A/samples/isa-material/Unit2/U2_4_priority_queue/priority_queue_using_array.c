#include<stdio.h>
#include<stdlib.h>
//program to implement  priority queue using an array
struct element
{
  int pty;
  int data;
};

typedef struct element element_t;
void pqinsert(element_t *,int , int ,int*);
element_t pqdelete(element_t*,int*);
void qdisplay(element_t*,int);

int main()
{
	int k,ch,pty,x;
	element_t pq[100],temp;
  
    int count=0;
	while(1)
	{
		//qdisplay(pq,count);
		printf("\n1..insert");
		printf("\n2..remove");
		printf("\n3..display");
		printf("\n4..EXIT");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the priority..");
					scanf("%d",&pty);
					printf("Enter the value");
					scanf("%d",&x);
					pqinsert(pq,x,pty,&count);
					break;
			case 2:	temp=pqdelete(pq,&count);
					if(temp.data>0)
					{
						printf("deleted element:- data=%d",temp.data);
						printf("   priority=%d\n",temp.pty);
					}
					break;
			case 4:	exit(0); 
		}
	}
}

void pqinsert(element_t *pq,int x,int pty,int*count)
{
	int j;
	element_t temp;
	  
	temp.data=x;
	temp.pty=pty;
	  
	j=*count -1;
	  
	while((j>=0)&&(pq[j].pty >temp.pty))
	{
		pq[j+1]=pq[j];
		j--;
	}
	pq[j+1]=temp;
	(*count)++;
}
	  
element_t pqdelete(element_t *pq ,int* count)
{
	int i;
	element_t temp;
	//if empty queue
	if((*count)==0)
	{
		printf("\nEmpty Queue..\n");
		temp.data=-1;
		temp.pty=-1;
	}
	else
	{
		temp=pq[0]; // get the first element
		for(i=1;i<*count;i++) //shift the elements
			pq[i-1]=pq[i];
	}
	(*count)--;
	return temp;
}
			
void qdisplay(element_t* pq,int count)
{
	int i;
	if(count==0)
		printf("\n Empty Queue...");
	else
	{
		for(i=0;i<count ; i++)
		    printf("\nvalue=%d priority=%d", pq[i].data, pq[i].pty);
	}
}

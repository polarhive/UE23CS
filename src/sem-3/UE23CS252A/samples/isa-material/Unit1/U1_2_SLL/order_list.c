#include<stdio.h>
#include<stdlib.h>
struct node
{
  int key;
  struct node *link;
  };
  
  typedef struct node node_t;
  
  struct list
  {
	  node_t* head;
 };
 typedef struct list list_t;
  
  void init_list(list_t*);
  void insert_order(list_t*,int);
  void display(list_t *);
  


int main()
{
	 list_t l;
	 init_list(&l);
	 int x;
	 display(&l);
	while(1)
	{
		printf("\nEnter the element");
		scanf("%d",&x);
	    if(x==0)
			break;
		insert_order(&l, x);
		printf("\n");
		display(&l);
	}
		
}

  void init_list(list_t *ptr_list)
  {
	  ptr_list->head=NULL;
  }
	  
void  insert_order(list_t *ptr_list, int x)
	  {
		  node_t *pres, *prev, *temp;
		  //create node
		  
		  temp= (node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
		  
		  prev=NULL;
		  pres=ptr_list->head;
		  //move forward until you find position or go beyond the list 
		  while((pres!=NULL)&&(x>pres->key))
		  {
		     prev=pres;
			 pres=pres->link;
		  }
		  if(pres!=NULL) //position found
		  {
			  if(prev==NULL)//first position, inserting smallest no.
			  {
		        ptr_list->head=temp;
				temp->link=pres;
		     }
		  else //prev not null, insert somewhere in middle 
		  {
			  temp->link=pres;
			  prev->link=temp;
		  }
		}
		else //pres is NULL	
		{
			if(prev==NULL) //inserting first no.
			    ptr_list->head=temp;
		   else	
			  prev->link=temp; // insert at end, largest no.
	     }
			  
	  }		  
			  
 void display(list_t *ptr_list)
	 {
		 node_t *pres;
        //is list empty ?
		if(ptr_list->head==NULL)
		   printf("\nEmpty list.\n");
	   else
	   {
		   //copy the address of the first node
		   pres=ptr_list->head;
		   while(pres!=NULL)
		   {
			   printf("%d-->",pres->key);
			   pres=pres->link;
		   }
	   }
	 }		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
	  
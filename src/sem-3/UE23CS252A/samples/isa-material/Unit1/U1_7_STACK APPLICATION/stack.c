#include"stack.h"

//function to initiliaze the stack
void init_stk(stack_t *ptr_st)
{
	printf("Enter the size of the stack");
	scanf("%d",&ptr_st->size);
	ptr_st->top=-1;
	
	ptr_st->s= (int*)malloc(sizeof(int)*ptr_st->size);
}

void push(stack_t * ptr_st, int key)
{
	//check for stack overflow
	if(ptr_st->top==ptr_st->size-1)
		printf("\nStack full..cannot insert element");
	else
	{
		++ptr_st->top;
		ptr_st->s[ptr_st->top]=key;
	}
}
		
	 void display(stack_t* ptr_st)
	 {
		int i;
		if(ptr_st->top==-1)
			printf("Stack empty..");
		else
		{
           for(i=ptr_st->top; i>=0;i--)
              printf("%d    ", ptr_st->s[i]);
		}
	 }		
		 
	int   pop(stack_t *ptr_st)
    {
		int k;
		//check for stack empty
		if(ptr_st->top==-1)  
		{
			printf("Empty stack..");
			return -1;
		}
		k=ptr_st->s[ptr_st->top];//copy the top element into k
		ptr_st->top--;
		return k;
	}
		
		
		
		
			
		
		


	
		 
		 
		 
		
		
		
		
		
		
		
	
	
	
	
	
	
	
//PROGRAM TO EVALUATE A GIVEN POSTFIX EXPRESSION
//INPUT IS OF THE FORM (eg. abc*+)
#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int *s;
	int size;
	int top;
};

typedef struct stack stack_t;

void init_stk(stack_t *);
void push(stack_t *, int);
 int   pop(stack_t *);
 int postfix_eval(char*);
 
int main()
{

 char postfix[100];
 printf("\nenter the postfix expression\n");
 scanf("%s",postfix);
 int result=postfix_eval(postfix);
 printf("\nthe result=%d\n",result);
 
}

int postfix_eval(char* postfix)
{
	int isoper(char );
	int i,result,op1,op2,a;
	char ch;
	i=0;
	stack_t st; //stack
	init_stk(&st); //initialise the stack
	while(postfix[i]!='\0')
	{
		ch=postfix[i];
		if(isoper(ch)) // if operator
		{
			 op1=pop(&st);
			 op2=pop(&st);
			 switch(ch)
			 {
				 case '+' : result=op1+op2;
				                  push(&st,result);
								  break;
				case '-':   result=op2-op1;
				                push(&st,result);
								  break;
			   case '*': result = op1*op2;
			                  push(&st,result);
								 break;
	            case '/' : result=op2/op1;
				                 push(&st,result);
								  break ;
			 }
		}			 
       else
	   {
		        printf("%c =",ch);
				scanf("%d",&a);
	            push(&st, a); 
	   }
	  i++;
	}
	 return(pop(&st)); //return the result
} 

//function to check if character is operand or operator
int isoper(char ch)
{
	if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/'))
		return 1;
	return 0;
}
	
//function to initiliaze the stack
void init_stk(stack_t *ptr_st)
{
	ptr_st->size=100; 
	ptr_st->top=-1;
	
	ptr_st->s= (int*)malloc(sizeof(int)*ptr_st->size);
}

void push(stack_t * ptr_st, int key)
{
		++ptr_st->top;
		ptr_st->s[ptr_st->top]=key;
	
}

int   pop(stack_t *ptr_st)
    {
		int k;
		k=ptr_st->s[ptr_st->top];//copy the top element into k
		ptr_st->top--;
		return k;
	}



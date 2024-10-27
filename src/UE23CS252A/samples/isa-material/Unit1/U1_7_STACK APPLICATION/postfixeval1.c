//PROGRAM TO EVALUATE A GIVEN POSTFIX EXPRESSION
//INPUT IS OF THE FORM (eg. abc*+)
#include "stack.h"
int main()
{
int postfix_eval(char*);

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
	
	
	



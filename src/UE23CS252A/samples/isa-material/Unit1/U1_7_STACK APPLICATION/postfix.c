//program to concert a valid infix expression to postfix
#include<stdio.h>
int input_prec(char);
int stack_prec(char);
char peep(char *,int);
void convert_postfix(char*,char*);
void push(char *, int *, char);
char pop(char *, int *);
int main()
{
  char infix[10],postfix[10];
  printf("\nEnter valid Infix Expression\n");
  scanf("%s",infix);
  convert_postfix(infix,postfix);
  printf("\nThe postfix equivalent=%s\n",postfix); 
}

void convert_postfix(char* infix,char* postfix)
{
	int i,j;
	char ch;
	char s[10];//stack
	int top=-1;
	i=0;
	j=0;
	push(s,&top,'#'); //push # to stack
	while(infix[i]!='\0')
	{
		ch=infix[i];
		while(stack_prec(peep(s,top)) >input_prec(ch))
		          postfix[j++]=pop(s,&top);
		if(input_prec(ch)>stack_prec(peep(s,top)))
				    push(s,&top,ch);
		  else
			  pop(s,&top); //for parenthesis
		  i++;
	}
	while(peep(s,top)!='#')	
                   postfix[j++]=pop(s,&top);		
	
	postfix[j]='\0';
}		 
			
	int stack_prec(char ch)
	{
		switch(ch)
		{
			case '+':
			case '-':return 2;
			case '*':
			case'/':return 4;
			case '(':return 0;
			case '#':return -1;
			default:return 6;
		}
	}
	
	int input_prec(char ch)
	{
		switch(ch)
		{
			case '+':
			case '-':return 1;
			case '*':
			case'/':return 3;
			case '(':return 7;
			case ')':return 0;
			default:return 5;
		}
	}
	
	char peep(char *s ,int top)
	{
		return s[top];
	}
	
		void push(char *s, int *top, char ch)
		{
			(*top)++; //or ++*top
			s[*top]=ch;
		}
		
		
		
     char pop(char *s, int *top)
	 {
		 char x;
		 x=s[*top];
		 --*top; //or (*top)--;
		 return x;
	 }
		 
		 
		 
		
	
	
	
	
	
	
	


Method 1.

#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
char s[20];
int top=-1;
void push(char ch)
{

  s[++top]=ch;
}
char pop()
{
  char ch;
  ch=s[top--];
  return(ch);
}

int precedence(char ch)
{

  switch(ch)
  {
    case '+':
    case '-':return(1);
    case '*':
    case '/':return (2);
    case '^':return (3);
    case '(':return (0);
  }
}
void infix_postfix(char infix[],char postfix[])
{ 
  //int top;
  int i=0;
  int j=0;
  char ch;
  push('(');
  for(i=0;i<strlen(infix);i++)
  {
    ch=infix[i]; //read input symbol to 'ch'
    if(isalnum(ch))
      postfix[j++]=ch;
    else if(ch=='(')
      push(ch);
    else if(ch==')')
    {
      while(s[top]!='(')
      postfix[j++]=pop();
      ch1=pop();
    }
    else
    {
      while(precedence(s[top]>=precedence(ch))//if pre(i/p)>pre(stack)-push()
      postfix[j++]=pop();
      push(ch);
    }
  }
  while(s[top]!='(')//till stack is empty
  postfix[j++]=pop();
  postfix[j]='\0';
}  
  
void main()
{
  char infix[20],postfix[20];
  //int i=0,j=0;
  printf("enter the infix expression\n");
  scanf("%s",infix);
  infix_postfix(infix,postfix);
  printf("postfix expression is=%s\n",postfix);
}

Alternate Method:
Alternate Method:
int F(char symbol)//stack precedence
{
  switch(symbol)
  {
    case '+':
    case '-':return 2;
    case '*'
    case '/':return 4;
    case '^':
    case '$': return 5;
    case '(':return 0;//on stack
    case '#':return -1;
    default: return 8;//on empty stack-'('
  }
}
int G(char symbol)//stack precedence
{
  switch(symbol)
  {
    case '+':
    case '-':return 1;
    case '*'
    case '/':return 3;
    case '^':
    case '$': return 6;
    case '(':return 9;//on stack
    case ')':return 0;//on empty stack-'('
    default :return 7;
  }
}
void infix_postfix(char infix[],char postfix[])
{ 
  //int top;
  int i;
  int j;
  int s[30];
  char symbol;
  top=-1;
  s[++top]='#';//push('(');
  j=0;
  for(i=0;i<strlen(infix);i++)
  {
    symbol=infix[i]; //read input symbol 
      while(F(s[top])>G(symbol))
      {
        postfix[j]=s[top--];//pop and place in postfix
        j++;
      }
      if(F(s[top])!=G(symbol))
      s[++top]=symbol;//push input to stack
    else
      top--;
  }
  while(s[top]!='#')//till stack is empty
  postfix[j++]=s[top--];
  postfix[j]='\0';
}  
  
void main()
{
  char infix[20],postfix[20];
  //int i=0,j=0;
  printf("enter the infix expression\n");
  scanf("%s",infix);
  infix_postfix(infix,postfix);//convert infix-potfix
  printf("postfix expression is\n");
  printf("%s\n",postfix);
}

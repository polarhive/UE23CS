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
void infix_prefix(char infix[],char prefix[])
{ 
  //int top;
  int i;
  int j;
  int s[30];
  char symbol;
  top=-1;
  s[++top]='#';//push('(');
  j=0;
strrev(infix);// Reverse the infix expression
  for(i=0;i<strlen(infix);i++)
  {
    symbol=infix[i]; //read input symbol 
      while(F(s[top])>G(symbol))
      {
        prefix[j]=s[top--];
        j++;
      }
      if(F(s[top])!=G(symbol))
      s[++top]=symbol;
    else
      top--;
  }
  while(s[top]!='#')//till stack is empty
  {
	prefix[j++]=s[top--];
   }
	prefix[j]='\0';
strrev(prefix);//Reverse postfix expression to get prefix expression
}  
  
void main()
{
  char infix[20],prefix[20];
  //int i=0,j=0;
  printf("enter the infix expression\n");
  scanf("%s",infix);
  infix_prefix(infix,prefix);//convert infix-potfix
  printf("prefix expression is\n");
  printf("%s\n",prefix);
}
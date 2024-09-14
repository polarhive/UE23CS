#include<stdio.h>
void push(char *s,int*,char);
char pop(char* s, int*);
int isempty(int);
int match(char *);
int main()
{
  char expr[10];
  printf("Enter the expression\n");
  scanf("%s",expr);
  int result=match(expr);
  if(result)
   printf("Matching of praenthesis succeeds\n");
 else
   printf("matching fails\n");
}

int match(char *expr){
   int i=0;
   char s[10];//stack
   int top=-1;
   while(expr[i]!='\0'){
     char x;
     char ch=expr[i];
     switch(ch){
       case '(':
       case '{':
       case '[':push(s,&top,ch);
                break;
       case ')':if(!isempty(top))//if stack empty, extra closing parenthesis
                {
                  x=pop(s,&top);
                  if(x=='(')
                    break;
                  else
                    return 0; //mismatch of parenthesis
                 }
                else
                   return 0;
       case '}':if(!isempty(top))//if stack empty, extra closing parenthesis
                {
                  x=pop(s,&top);
                  if(x=='{')
                    break;
                  else
                    return 0; //mismatch of parenthesis
                 }
                else
                   return 0;

       case ']':if(!isempty(top))//if stack empty, extra closing parenthesis
                {
                  x=pop(s,&top);
                  if(x=='[')
                    break;
                  else
                    return 0; //mismatch of parenthesis
                 }
                else
                   return 0;

       }//end switch
       i++;
     }//end while
     if(isempty(top))
       return 1;
     return 0;//extra opening parenthesis
   }

int isempty(int top){
     if(top==-1)
       return 1;
     return 0;
  }

void push(char *s,int *t,char x){
   ++*t;//increment top
   s[*t]=x;
  }

char pop(char *s, int *t){
    char x;
    x=s[*t];
    --*t;//decrement top
    return x;
  }













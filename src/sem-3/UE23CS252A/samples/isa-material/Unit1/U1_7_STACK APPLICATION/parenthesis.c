#include<stdio.h>
void push(char *,int*,char);
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
   printf("Matching is correct\n");
 else
   printf("matching fails\n");
}

  int match(char *str)
  {
	  char s[10];//stack
	  char ch,x;
	  int top=-1;
	  int i=0;
	  while(str[i]!='\0')
	  {
		  ch=str[i];
	      switch(ch)
		  {
			  case '(':
			  case'{':
			  case'[': push(s,&top,ch);
			                break;
			  case')': if(!isempty(top))
			               {
				                x=pop(s,&top);
								if(x!='(') //paranthesis mismatch
									return 0; 
								break;
						   }
						   else
							   return 0 ;//extra closing paraenthesis
						  
			  case'}': if(!isempty(top))
			               {
				                x=pop(s,&top);
								if(x!='{') //paranthesis mismatch
									return 0;
								break;
						   }
						   else
							   return 0;	//extra closing paraenthesis  
				case']': if(!isempty(top))
			               {
				                x=pop(s,&top);
								if(x!='[') //paranthesis mismatch
									return 0;
								break;
						   }
						   else
							   return 0;	//extra closing paraenthesis  
			  } //end switch
			  i++;
		  } //end while
		if(isempty(top))
			return 1; //parenthesis match
		return 0; //extra opening parenthesis
	  }
	

    void push(char *s, int *t,char ch)
	{
		(*t)++; //or ++*t
		s[*t]=ch;
	}
	
	char pop(char *s, int *t)
	{
		char x;
		x=s[*t];
		(*t)--;  //or --*t
	    return x;
	}
		
int isempty(int t)
{
	if(t==-1)
		return 1;
	return 0;
}







	
			  
			  
			  
			  
			  
			  
			  







			  
							
							
							
			  
			  
			  
			  
			  
	  
	  
	  
	  
	  
	  
	  
	  
	  
















 




#include <stdio.h>
#define STACK_SIZE 5
int top;
int s[10];
int item;

void push()
{
  if(top==STACK_SIZE-1)
  {
    printf("stack is empty\n");
    return;
  }
  top=top+1;
  s[top]=item;
}
int pop()
{
  if(top==-1)return -1;
  s[top--];
}
void display()
{
  //int i;
  if(top==-1)
  {
    printf("Stack is empty\n");
    return;
  }
  printf("Contents of the stack are\n");
  for(top=0;top<=STACK_SIZE-1;top++)
  {
    printf("%d\n",s[top]);
  }
}

void main()
{
  int item_deleted;
  int choice;
  top=-1;
  for(;;)
  {
    printf("1:push 2:pop\n");
    printf("3:Display 4:exit\n");
    printf("enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("enter the item to be inserted\n");
              scanf("%d",&item);
              push();
              break;
      case 2: item_deleted=pop();
              if(item_deleted==-1)
                  printf("Stack is empty\n");
              else
                  printf("Item deleted = %d\n", item_deleted);
              break;
      case 3: display();
              break;
      default: exit(0);
    }
  }
}
// program to demonstrate fork() 
#include<unistd.h>
#include<stdio.h>
int main()
{
    pid_t   p1;
    p1=fork();
    if (p1<0)
   {
	printf("fork failed");
    }
    else if (p1==0)
    {
     printf("child process\n");
     }
    else
    {
     printf("parent process\n");
     }
return 0;
}


// program to demonstrate sending a signal to a child process 

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    pid_t p1;

    p1 = fork();

    if (p1 > 0) //parent process
    {
        sleep(2);

        printf("This is parent. Process Id = %d\n", getpid());

        kill(p1, SIGQUIT);

        sleep(2);

        printf("This is parent after terminating the child. Process Id = %d\n", getpid());

    }
    else if (p1 == 0) // child process 
    {
        while(1)
           printf("This is child. Process Id = %d, Parent Process Id = %d\n", getpid(), getppid());
    }
    else //fork failed
    {
        printf("fork creation failed!!!\n");
    }
}

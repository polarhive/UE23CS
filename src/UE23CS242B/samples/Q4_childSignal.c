#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void sigFunc(int sig)
{
    if (sig == SIGINT)
    {
        printf("Received SIGINT in child process.\n");
        exit(0);
    }
}

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child waiting for SIGINT\n");
        signal(SIGINT, sigFunc);
        pause();
    }
    else if (pid < 0)
    {
        perror("Error in child process creation");
        exit(1);
    }
    else
    {
        sleep(1);
        printf("Parent sending SIGINT\n");
        kill(pid, SIGINT);
        wait(NULL);
    }

    return 0;
}

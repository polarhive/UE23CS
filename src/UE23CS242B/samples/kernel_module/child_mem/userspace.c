#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define NUM_CHILDREN 3

// Function to print the memory map using pmap
void print_memory_map(pid_t pid)
{
    char cmd[50];
    snprintf(cmd, sizeof(cmd), "pmap -x %d", pid);
    system(cmd);
}

int main()
{
    // Get and print the parent PID
    pid_t parent_pid = getpid();
    printf("Parent PID: %d\n", parent_pid);

    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            // In child process
            printf("   |--Child PID: %d (PPID: %d)\n", getpid(), getppid());

            // Allocate dynamic memory
            int *dmem = (int *)malloc(10 * sizeof(int));
            if (dmem == NULL)
            {
                perror("Memory allocation failed\n");
                exit(1);
            }

            printf("      |--Dynamic Memory Address: %p\n", dmem);

            // Print the memory map of the current child process
            print_memory_map(getpid());

            // Simulate work for 5 seconds
            sleep(5);

            // Free allocated memory
            free(dmem);

            exit(0);
        }
        else if (pid < 0)
        {
            // Fork failed
            perror("Fork Failed\n");
        }
    }

    // Parent waits for all children to finish
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        wait(NULL);
    }

    return 0;
}

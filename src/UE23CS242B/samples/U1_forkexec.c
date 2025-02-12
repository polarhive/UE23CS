// program to demonstrate creation of child processes and executing commands using fork(), execl() and wait() 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Starting the program. Parent PID: %d\n", getpid());

    pid = fork(); // Create a child process

    if (pid < 0)
   {
        // Fork failed
        printf("fork failed");
   } 
   else if (pid == 0) 
{
        // Child process
        printf("This is the child process. PID: %d, Parent PID: %d\n", getpid(), getppid());

        // Replace the current process image with the "ls" program
        //printf("Child is executing 'ls -l' command using execl:\n");
       // execl("/usr/bin/ls", "ls" , NULL); //execl allows passing arguments as a variable length list
       

          char *args[] = {"wel", NULL}; // Argument array, must end with NULL

        // Replace the current process image with the "wel.exe" program
         printf("Child is executing 'wel' command using execv:\n");
        
         execv("/mnt/c/Users/Neha Sharma/cc/wel" , args); //execv allows passing arguments as an array of strings
       //If execv fails
       printf("execv failed\n");
  }
 
else {
        // Parent process
        printf("Parent is waiting for the child process to finish...\n");
        wait(NULL); // Wait for the child process to terminate
        printf("Child process has finished. Parent process is resuming. PID: %d\n", getpid());
    }

return 0;
}
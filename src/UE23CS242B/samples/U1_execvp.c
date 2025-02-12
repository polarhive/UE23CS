#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    printf("Using execvp() to execute `wel`:\n");

    char *args[] = { "wel", NULL };

    if (fork() == 0) {
        // Child process
        execvp("wel", args); //automatically searches path env var to locate the program,use export command to add the path to env. var.
        // If execvp() fails
        perror("execvp failed");
        exit(1);
    }

    // Parent process waits for child
    wait(NULL);
    printf("execvp() example finished.\n");
    return 0;
}
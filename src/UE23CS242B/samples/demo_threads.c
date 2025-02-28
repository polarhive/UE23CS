// program to demo threads
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// create a global variable which will be changed in the threads
int g = 0;

// The function to be executed by all threads
void *myThreadFunction(void *vargp)
{
    // Store the value argument passed to this thread
    int *myid = (int *)vargp;

    // Let us create a static variable to observe its changes
    static int s = 0;

    // Let us create a local variable to observe its changes
    int l = 0;
    
    // Change local, static and global variables
    ++l; ++s; ++g;

    // Print the argument, static and global variables
    printf("Thread ID: %d, Local: %d, Static: %d, Global: %d\n", *myid, l, s, g);

    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t tid;

    // Let us create three threads
    for (i = 0; i < 3; i++)
    {
	pthread_create(&tid, NULL, myThreadFunction, (void *)&tid);
        pthread_join(tid, NULL);
    }

    printf("In main()\n");
    return 0;
}

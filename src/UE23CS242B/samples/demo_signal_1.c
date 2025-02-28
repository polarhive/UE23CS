// Program to demo custom signal handler

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void my_signal_handler(int sig)
{

   printf("Ouch!!! encountered a floating point error\n");
   (void) signal(SIGFPE, SIG_DFL);
}

int main()
{

   (void) signal(SIGFPE, my_signal_handler);

   int n = 0, d = 0;

   printf("Enter a numerator: ");
   scanf("%d", &n);

   printf("Enter a denominator: ");
   scanf("%d", &d);

   int result = n / d;

   printf("Result = %d\n", result);
}



#include <stdio.h>

int main(void) 
{
  register int i; // i is declared as a register variable
  for (i = 0; i < 1000000; i++)
  ;
  
  printf ("Address is %p\n", &i); // Should be a compilation error
  return 0;
}
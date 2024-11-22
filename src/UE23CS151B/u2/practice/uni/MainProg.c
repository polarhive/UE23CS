#include <stdio.h>
#include "function.h"

int x; // value of the global variable x is shared across files

int main(void)
{
  x = 5;
  printf("Value of x before increment: %d\n", x);
  increment();
  printf("Value of x after increment: %d\n", x);

  return 0;
}

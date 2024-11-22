#include <stdio.h>

void function()
{
  static int x = 0; // x is declared as a static variable
  x++;
  printf("Value of x: %d\n", x);
}

int main(void)
{
  function(); // x is 1
  function(); // x is 2
  return 0;
}
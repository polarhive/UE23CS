#include <stdio.h>

void function()
{
  auto int x = 1; // x is an auto variable
  printf("Value of x: %d\n", x);
  x++;
  printf("Value of x after increment: %d\n", x);
}

int main(void)
{
  function();
  function();
  return 0;
}
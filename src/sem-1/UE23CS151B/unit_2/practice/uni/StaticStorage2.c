#include <stdio.h>

static int s_glob = 1;
void function()
{
  printf("s_glob value is %d\n", s_glob);
  s_glob++;
}

int main(void)
{
  function();
  printf("s_glob value in main in %d\n", s_glob);
  return 0;
}
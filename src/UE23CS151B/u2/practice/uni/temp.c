#include <stdio.h>

extern int s_glob;

void function1()
{
  printf("s_glob value is %d\n", s_glob);
  s_glob++;
}

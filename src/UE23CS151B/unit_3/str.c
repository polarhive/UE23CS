#include <stdio.h>
#include <string.h>
int main()
{
  char str[]="hello";
  printf("%p\n", &str);
  printf("%s\n", str);
}

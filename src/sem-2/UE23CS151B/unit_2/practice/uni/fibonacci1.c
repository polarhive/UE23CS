#include <stdio.h>

int fibonacci_01(int i)
{

  if (i == 0)
    return 0;

  if (i == 1)
    return 1;

  return fibonacci_01(i - 1) + fibonacci_01(i - 2);
}

int main(void)
{
  int i, n;
  printf("Enter a digit for fibonacci series: \n");
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    printf(" %d ", fibonacci_01(i));
  }

  return 0;
}

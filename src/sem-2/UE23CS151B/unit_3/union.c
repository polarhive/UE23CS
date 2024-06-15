#include<stdio.h>
union test
{
  int x;
  float y; 
}; 

int main(void)
 {
    union test t; 
    t.x = 5;
    printf("%d\n", t.x);
    t.y = 5;
    printf("%f\n", t.y);
    printf("%d\n", t.x);
}

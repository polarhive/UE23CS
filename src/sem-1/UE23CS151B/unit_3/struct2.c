#include <stdio.h>
struct Point {
  int x;
  int y;
}

p1={1,2} // same thing
;

int main(){
  /*instance of a struct:*/ struct Point p1={1,2};
  printf("coords: (%d, %d)\n", p1.x, p1.y);
}

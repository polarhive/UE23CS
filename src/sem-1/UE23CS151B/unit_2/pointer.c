#include <stdio.h>

int main() {
	int num = 10;
	int *ptr = &num;

  // * dereference operator, used to access the value at a pointer's address.
  printf("Value of num: %d\n", num); //10
  printf("Address of num: %p\n", &num); //some hex value
  printf("Value of num via pointer: %d\n", *ptr); //10 by deref the pointer
  printf("Address stored in pointer: %p\n", ptr);
}

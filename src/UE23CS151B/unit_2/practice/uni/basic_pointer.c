#include <stdio.h>
int main (void)
{
	int i = 20, *pi = &i;
	printf ("The pointer value is: %p\n", pi);
	pi ++;

	printf ("After incrementing, the pointer value is: %p\n", pi);
	return 0;
}

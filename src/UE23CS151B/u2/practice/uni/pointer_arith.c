// Program to demonstrate pointer arithmetic
#include <stdio.h>

int main(void)
{
	char c1;
	int i1;
	short s1;
	long l1;
	char *c_ptr = &c1;
	int *i_ptr = &i1;
	short *s_ptr = &s1;
	long *l_ptr = &l1;

	printf("Char pointer is %p\n", c_ptr);
	printf("Short pointer is %p\n", s_ptr);
	printf("int pointer is %p\n", i_ptr);
	printf("Long pointer is %p\n", l_ptr);
	c_ptr++;
	s_ptr++;
	i_ptr++;
	l_ptr++;

	printf("After the increment operation\n");
	printf("Char pointer is %p\n", c_ptr);
	printf("Short pointer is %p\n", s_ptr);
	printf("int pointer is %p\n", i_ptr);
	printf("Long pointer is %p\n", l_ptr);

	return 0;
}
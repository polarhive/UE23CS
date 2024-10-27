#include <stdio.h>
int what(int x, int y, int (*op)(int, int))
{
	return op(x, y);
}
int add(int x, int y)
{
	return x + y;
}
int div(int x, int y)
{
	return x / y;
}
int main()
{
	printf("Result=%d\n", what(1, 3, add));
	printf("Result=%d\n", what(4, 2, div));
	return 0;
}

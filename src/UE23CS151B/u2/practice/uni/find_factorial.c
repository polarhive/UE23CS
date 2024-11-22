#include <stdio.h>
#include <stdlib.h>

int fact(int num)
{
	if (num <= 1)
		return 1;
	else
		return num * fact(num - 1);
}
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Please pass a number as a command line argument\n");
		exit(0);
	}

	int num = atoi(argv[1]);
	printf("Factorial of %d is %d\n", num, fact(num));
	return 0;
}

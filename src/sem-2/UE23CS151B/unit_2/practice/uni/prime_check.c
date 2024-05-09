#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime(int num)
{
	int divisor;

	if (num <= 1)
		return false;

	for (divisor = 2; divisor * divisor <= num; divisor++)
		if (num % divisor == 0)
			return false;
	return true;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Please provide a command line argument\n");
		exit(0);
	}

	int num = atoi(argv[1]);
	bool res = is_prime(num);

	res ? printf("%d is a prime number\n", num) : printf("%d is not a prime number\n", num);
	return 0;
}

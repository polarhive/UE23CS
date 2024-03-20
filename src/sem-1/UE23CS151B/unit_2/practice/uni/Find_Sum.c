#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int sum = 0;

	if (argc < 2)
	{
		printf("You have not entered any arguments\n");
		exit(0);
	}
	for (int i = 1; i < argc; i++)
		sum += atoi(argv[i]);

	printf("The sum is %d\n", sum);
	return 0;
}
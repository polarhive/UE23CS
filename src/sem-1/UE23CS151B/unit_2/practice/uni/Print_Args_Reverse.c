#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
		printf("Arg%d is %s\n", argc - 1 - i, argv[argc - 1 - i]);
	return 0;
}
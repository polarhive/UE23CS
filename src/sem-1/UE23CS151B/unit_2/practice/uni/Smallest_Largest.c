#include <stdio.h>
#include <string.h>

int main(void)
{
	char inp_str[50];
	char smallest[50];
	char largest[50];

	smallest[0] = '\0';
	largest[0] = '\0';
	while (1)
	{
		printf("Key in a string:");
		scanf("%s", inp_str);
		if (strcmp(inp_str, "quit") == 0)
			break;
		if (strlen(smallest) == 0)
			strcpy(smallest, inp_str);
		if (strlen(largest) == 0)
			strcpy(largest, inp_str);

		if (strlen(inp_str) < strlen(smallest))
			strcpy(smallest, inp_str);
		if (strlen(inp_str) > strlen(largest))
			strcpy(largest, inp_str);
	}
	printf("The smallest string is %s\n", smallest);
	printf("The largest string is %s\n", largest);
	return 0;
}

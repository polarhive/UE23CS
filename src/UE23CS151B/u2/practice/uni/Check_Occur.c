#include <stdio.h>
#include <string.h>

int main (void)
{
	char inp_str [80];
	char toCheck;
	int count = 0;
	char *p_str = &inp_str[0];
	char *temp;

	printf ("Key in the string:");
	scanf ("%s", inp_str);
	printf ("Key in the character to check for:");
	scanf (" %c", &toCheck);

	while (*p_str != '\0')
	{
		if ((temp = strchr (p_str, toCheck)) != NULL)
		{
			p_str = temp + 1;
			count ++;
		}
		else
			p_str ++;
	}
	printf ("Found %d occurrences of %c\n", count, toCheck);
	return 0;
}
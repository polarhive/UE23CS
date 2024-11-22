#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str = "My name is abcd I am from XYZ";
	char temp [80]; 
	int count = 0;

	strcpy (temp, str);

	while (*str != '\0')
	{
		if (*str == ' ')
			count ++;
		str ++;
	}

	printf ("Found %d spaces in the string \n%s\n", count, temp);
	return 0;
}


// Program to find the length of a given string
#include <stdio.h>

int main(void)
{
	char m_str[30];
	int len;

	printf("Please key in a string with spaces:");
	scanf("%[^\n]", m_str);

	for (len = 0; m_str[len] != '\0'; len++)
		;
	printf("Length of the string is %d\n", len);
	return 0;
}

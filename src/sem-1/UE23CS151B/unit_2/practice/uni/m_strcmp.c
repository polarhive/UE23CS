// Program to compare two strings
#include <stdio.h>

int main(void)
{
	char m_str1[50], m_str2[50];
	int len1, len2, tmp;

	printf("Please key in the first string with spaces:");
	scanf("%[^\n]", m_str1);

	printf("Please key in the second string with spaces:");
	scanf(" %[^\n]", m_str2);

	// Find the length of the first string
	for (len1 = 0; m_str1[len1] != '\0'; len1++)
		;

	// Find the length of the second string
	for (len2 = 0; m_str2[len2] != '\0'; len2++)
		;

	if (len1 == len2) // makes sense to compare
	{
		for (tmp = 0; tmp < len1; tmp++)
		{
			if (m_str1[tmp] != m_str2[tmp])
			{
				printf("The two strings are not the same\n");
				break;
			}
		}
		if (tmp == len2)
			printf("The two strings are the same\n");
	}
	else
		printf("The two strings are not the same\n");
	return 0;
}

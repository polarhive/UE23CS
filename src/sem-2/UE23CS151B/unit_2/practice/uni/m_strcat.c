// Program to concatenate two strings
#include <stdio.h>

int main (void)
{
	char m_str1 [100], m_str2 [30];
	int len;

	printf ("Please key in the first string with spaces:");
	scanf("%[^\n]", m_str1); 
	printf ("Please key in the second string with spaces:");
	scanf(" %[^\n]", m_str2); 

	// We will concatenate the two strings and m_str1 will contain the resulting
        // string

	for (len = 0; m_str1 [len] != '\0'; len ++)
		;
	// printf ("Length of the first string is %d\n", len);

	for (int i = 0; m_str2 [i] != '\0'; i ++)
		m_str1 [len+i] = m_str2[i];

	printf ("The resulting string is %s\n", m_str1);

	return 0;
}


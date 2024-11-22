// Program to reverse a string
#include <stdio.h>

int main(void)
{
	char m_str1[50], m_str2[50];
	int len, tmp;

	printf("Please key in the first string with spaces:");
	scanf("%[^\n]", m_str1);

	// Find the length of the given string
	for (len = 0; m_str1[len] != '\0'; len++)
		;

	// Store the reversed string in a temporary array
	for (tmp = 0; tmp < len; tmp++)
		m_str2[tmp] = m_str1[len - tmp - 1];

	m_str2[tmp] = '\0';

	// Copy the reversed string back to the original string

	for (tmp = 0; m_str2[tmp] != '\0'; tmp++)
		m_str1[tmp] = m_str2[tmp];
	m_str1[tmp] = '\0';

	printf("The reversed string is %s\n", m_str1);

	return 0;
}

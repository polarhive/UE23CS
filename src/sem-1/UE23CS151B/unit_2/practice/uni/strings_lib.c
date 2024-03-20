// Program containing our version of string operations
#include <stdio.h>

void m_strcpy(char *m_dest, char *m_srce)
{
	int len;
	for (len = 0; *m_srce != '\0'; len++)
		*m_dest++ = *m_srce++;
	*m_dest = '\0';
}

int m_strlen(char *srce)
{
	int slen = 0;
	for (slen = 0; *srce != '\0'; srce++, slen++)
		;
	return slen;
}

void m_strrev(char *srce)
{
	int len = m_strlen(srce);
	char temp[len + 1];
	int tmp;

	// Store the reversed string in a temporary array
	for (tmp = 0; tmp < len; tmp++)
		temp[tmp] = srce[len - tmp - 1];
	temp[tmp] = '\0';

	m_strcpy(srce, temp);
}

// Returns 0 when the two strings are the same; else 1
int m_strcmp(char *str1, char *str2)
{
	int res = 0;
	int tmp;

	int len1 = m_strlen(str1);
	int len2 = m_strlen(str2);

	if (len1 == len2) // makes sense to compare
	{
		for (tmp = 0; tmp < len1; tmp++)
		{
			if (*str1++ != *str2++)
			{
				res = 1;
				break;
			}
		}
	}
	else
		res = 1;
	return res;
}

// dest will contain the concatenated string
void m_strcat(char *dest, char *srce)
{
	int len = m_strlen(dest);
	int i;

	for (i = 0; srce[i] != '\0'; i++)
		dest[len + i] = srce[i];

	// printf ("len+i is %d\n", len+i);
	dest[len + i] = '\0';
}

int main(void)
{
	char m_str1[100], m_str2[50];
	int len, res;

	printf("Please key in the first string with spaces:");
	scanf("%[^\n]", m_str1);
	printf("Please key in the second string with spaces:");
	scanf(" %[^\n]", m_str2);
	res = m_strcmp(m_str1, m_str2);
	res ? printf("The two strings are not the same\n") : printf("The two strings are the same\n");

	m_strcat(m_str1, m_str2);
	printf("The resulting string is %s\n", m_str1);

	m_strrev(m_str1);
	printf("The reversed string is %s\n", m_str1);

	return 0;
}

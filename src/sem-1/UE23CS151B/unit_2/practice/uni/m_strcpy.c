// Program to copy one string to another
#include <stdio.h>

int main (void)
{
	char m_srce [50], m_dest [50];
	int len;

	printf ("Please key in the source string with spaces:");
	scanf("%[^\n]", m_srce); 
	
	for (len = 0; m_srce [len] != '\0'; len ++)
		m_dest [len] = m_srce [len];
	m_dest [len] = '\0';

	printf ("The copied string is %s\n", m_dest);
 
	return 0;
}


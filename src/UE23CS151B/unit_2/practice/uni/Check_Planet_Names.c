#include <stdio.h>
#include <string.h>

int main (void)
{

	char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter",
			"Saturn", "Uranus", "Neptune", NULL
			};

	char inp_str [20];

	while (1)
	{
		printf ("Key in a planet name:");
		scanf ("%s", inp_str);
		if (strcmp (inp_str, "quit") == 0)
			break;
		for (int i = 0; planets [i] != NULL; i ++)
		{
			if (strcmp (inp_str, planets[i]) == 0)
			{
				printf ("%s is a planet name\n", inp_str);
				break;
			}
		}
	}
	return 0;
}
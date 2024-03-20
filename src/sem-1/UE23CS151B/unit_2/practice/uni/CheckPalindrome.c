#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
	char *str = "KANNADA"; // "MALAYALAM", "racecar", "madam", etc
	bool ret_val = true;
	int low = 0;
	int high = strlen (str) - 1;
	
	// Keep comparing characters while they are same
	while (low < high) 
 	{
		if (*(str + low) != *(str + high))
		{
			ret_val = false; // not a palindrome.
			break;
		}
		low++; // move the low index forward
		high--; // move the high index backwards
	}
	
	ret_val? printf ("The string %s is a palindrome\n", str):
			printf ("The string %s is not a palindrome\n", str);
	return 0;
}

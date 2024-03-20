/*
Write a program that accepts a date from the user in the form mm/dd/yyyy and then displays it in the form month dd, yyyy where month is the name of the month (Ex. January, February, etc). Store the month names in an array
*/

#include <stdio.h>
#include <string.h>

int main (void)
{
	char inp_str [12];
	int mnth = 0, day = 0, year = 0;
	int i;
	int month;
	char i_temp [5];
	char months[][12] = {"January", "February", "March",
			"April", "May", "June", "July", "August", "September", "October", "November", "December"
			};
	printf ("Key in the day in the format mm/dd/yyyy:");
	scanf ("%s", inp_str);

	// Extracting the month from the input string
	for (i = 0; i < 2; i ++)
		i_temp [i] = inp_str [i];
	i_temp [i] = '\0';

	// Converting a string to the corresponding number.
	for (int i = 0; i_temp[i] != '\0'; ++i)
        	mnth = mnth * 10 + i_temp[i] - '0';
	
	// Extracting the day from the input string
	for (i = 0; i < 2; i ++)
		i_temp [i] = inp_str [3 + i];
	i_temp [i] = '\0';

	// Converting a string to the corresponding number.
	for (int i = 0; i_temp[i] != '\0'; ++i)
        	day = day * 10 + i_temp[i] - '0';

	// Extracting the year from the input string
	for (i = 0; i < 4; i ++)
		i_temp [i] = inp_str [6 + i];
	i_temp [i] = '\0';

	// Converting a string to the corresponding number.
	for (int i = 0; i_temp[i] != '\0'; ++i)
        	year = year * 10 + i_temp[i] - '0';

	printf ("%s %d, %d\n",months[mnth], day, year);
	return 0;
}


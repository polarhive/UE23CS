/*
Write a program that accepts a date from the user in the form mm/dd/yyyy and then displays it in the form month dd, yyyy where month is the name of the month (Ex. January, February, etc). Store the month names in an array
*/

#include <stdio.h>
#include <string.h>

// Function to convert a string to the corresponding number
int ConvStrToInt(char *str)
{
	int res = 0;
	// Converting a string to the corresponding number.
	for (int i = 0; str[i] != '\0'; ++i)
		res = res * 10 + str[i] - '0';
	return res;
}

void Extract(char *inp_str, int size, char *buf)
{
	int i;

	for (i = 0; i < size; i++)
		buf[i] = *inp_str++;
	buf[i] = '\0';
}

int main(void)
{
	char inp_str[12];
	int mnth = 0, day = 0, year = 0;
	int i;
	char i_temp[5];
	char months[][12] = {"January", "February",
						 "March", "April",
						 "May", "June",
						 "July", "August",
						 "September", "October",
						 "November", "December"};
	printf("Key in the date in the format mm/dd/yyyy:");
	scanf("%s", inp_str);

	Extract(&inp_str[0], 2, i_temp);

	mnth = ConvStrToInt(i_temp);

	Extract(&inp_str[3], 2, i_temp);

	day = ConvStrToInt(i_temp);

	Extract(&inp_str[6], 4, i_temp);

	year = ConvStrToInt(i_temp);

	printf("%s %d, %d\n", months[(mnth - 1) % 12], day, year);
	return 0;
}

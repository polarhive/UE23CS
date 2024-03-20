// Pointers and multi-dimensional arrays

#include <stdio.h>

int main(void)
{
	int i_arr[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *pi_arr = &i_arr[0][0];

	// Print the elements of the first row
	// Compare two pointers
	for (pi_arr = &i_arr[0][0]; pi_arr < &i_arr[1][0]; pi_arr++)
		printf("Element is %d\n", *pi_arr);

	return 0;
}

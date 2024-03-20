// Pointers and multi-dimensional arrays

#include <stdio.h>

int main(void)
{
	int i_arr[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i, j;
	int num_elems = sizeof(i_arr) / sizeof(int);
	int *pi_arr = &i_arr[0][0];

	// How do you print all the elements of the array
	for (i = 0; i < 2; i++)
		for (j = 0; j < 5; j++)
			printf("Element %d %d is %d\n", i, j, i_arr[i][j]);

	// Viewing the 2 D array as 1D array of num_elems elements
	// Internally 2D array is stored as a 1D array

	printf("Element i_arr[0][3] is %d\n", *(pi_arr + 3));

	for (int k = 0; k < num_elems; k++)
		printf("Element %d is %d\n", k + 1, *pi_arr++);
	return 0;
}

// Use the name of a multi-dimensional array as a pointer

#include <stdio.h>

int main(void)
{
	int i_arr[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
	// i_arr is not a pointer to i_arr but a pointer to i_arr [0]
	int *pi_arr, k;
	int num_elems = sizeof(i_arr) / sizeof(int);

	// For clearing column i (In this case 0) of the array
	for (pi_arr = i_arr; pi_arr < (i_arr + 2); pi_arr++)
		(*pi_arr)[0] = 0;

	for (pi_arr = &i_arr[0][0], k = 0; k < num_elems; k++)
		printf("Element %d is %d\n", k + 1, *pi_arr++);
	return 0;
}

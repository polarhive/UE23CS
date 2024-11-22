#include <stdio.h>

int main(void)
{
	int i_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *p_arr;

	for (p_arr = i_arr + 9; p_arr >= i_arr; p_arr--)
		printf("%d ", *p_arr);

	return 0;
}

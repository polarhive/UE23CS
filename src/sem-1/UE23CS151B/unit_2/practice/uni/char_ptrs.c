/*
char* is a mutable pointer to a mutable character/string.
const char* is a mutable pointer to an immutable character/string. You cannot change the contents of the location(s) this pointer points to. Also, compilers are required to give error messages when you try to do so. For the same reason, conversion from const char * to char* is deprecated.
char* const is an immutable pointer (it cannot point to any other location) but the contents of location at which it points are mutable.
const char* const is an immutable pointer to an immutable character/string
*/

#include <stdio.h>
int main (void)
{
	char arr1 [20], arr2 [30], arr3 [40];

	char *ptr = arr1;
	const char *c_ptr = arr3;
	char *const c_ptr1 = arr1;
	const char* const c_ptr2 = arr1;

	// See if you can make the pointer point to any other address
	ptr = arr2;
	// See if you can change the content of the pointer
	*(ptr+1) = 'B';
	c_ptr = arr2;	// You can make the pointer pont to a different address
	*(c_ptr + 2) = 'C';	// Cannot change the content 
	c_ptr1 = arr3;	// Cannot point to a different address
	*(c_ptr1 + 2) = 'C';	// You can change the content
	c_ptr2 = arr2;	// Cannot point to a different address
	*(c_ptr2 + 2) = 'B'; 	// Cannot change the content too
	return 0;

}

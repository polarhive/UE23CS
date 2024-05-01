#include <stdio.h>
#include <stdlib.h>

int main()
{

/*
- malloc(sizeof(int)) allocates memory for one integer.
- the result of malloc() is a pointer to the allocated memory, but its type is void*.
- (int*) is a type cast. It converts the void* pointer to -->  an int*, indicating that the pointer points to an integer.

int *ptr = ...
- Declares a pointer ptr of type int*.
- ptr is then assigned the memory address returned by malloc() after typecasting.
*/

int *ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Memory address allocated: %p\n", (void*)ptr);
    printf("Size of allocated memory: %lu bytes\n", sizeof(int));

    *ptr = 10;
    printf("Value stored in the allocated memory: %d\n", *ptr);

    free(ptr);

    return 0;
}

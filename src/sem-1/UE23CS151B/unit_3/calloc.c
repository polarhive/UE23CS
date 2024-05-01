/*
 calloc()

void *calloc(size_t num, size_t size);

- calloc(): allocates memory for an array of elements, each with a size of size bytes.
- It initializes the allocated memory block to zero.

  It takes two arguments:
  * num: Number of elements to allocate.
  * size: Size of each element in bytes.

example:
int *ptr = (int*)calloc(5, sizeof(int));

This allocates memory for an array of 5 integers and initializes all elements to zero.

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)calloc(5, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // No need to initialize values with calloc()

    // Print values
    printf("Using calloc():\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(ptr);

    return 0;
}

/*
  realloc():
  void *realloc(void *ptr, size_t size);

  -realloc() changes the size of the previously allocated memory block pointed to by ptr to the new size size.
  - It may move the memory block to a new location.
  - It returns a pointer to the reallocated memory block, or NULL if the reallocation fails.

  - If ptr is NULL, realloc() behaves like malloc() and allocates a new memory block.
  - If size is zero, realloc() deallocates the memory block pointed to by ptr.

ptr = (int*)realloc(ptr, 10 * sizeof(int));

This reallocates the memory block pointed to by ptr to be able to hold 10 integers.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(5 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize values
    for (int i = 0; i < 5; i++) {
        ptr[i] = i + 1;
    }

    // Reallocate memory
    ptr = (int*)realloc(ptr, 10 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    // Initialize additional values
    for (int i = 5; i < 10; i++) {
        ptr[i] = i + 1;
    }

    // Print values
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);

    return 0;
}

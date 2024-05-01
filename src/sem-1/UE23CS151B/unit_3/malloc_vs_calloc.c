/*
## malloc()
void *malloc(size_t size);

Initialization:

    malloc() allocates a block of memory of the given size in bytes.
    The contents of the allocated memory are uninitialized; it may contain garbage values.

Arguments:

    size: Size of the memory block to allocate in bytes.

Return Value:

    If the allocation is successful, malloc() returns a pointer to the allocated memory block.
    If the allocation fails (due to insufficient memory), it returns NULL.

Example:

    int *ptr = (int*)malloc(5 * sizeof(int));

## calloc()
void *calloc(size_t num, size_t size);

Initialization:

    calloc() allocates memory for an array of elements.
    It initializes the allocated memory block to zero.

Arguments:

    num: Number of elements to allocate.
    size: Size of each element in bytes.

Return Value:

    If the allocation is successful, calloc() returns a pointer to the allocated memory block.
    If the allocation fails (due to insufficient memory), it returns NULL.

Example:

    int *ptr = (int*)calloc(5, sizeof(int));

Comparison

    Initialization:
        malloc() does not initialize the allocated memory, which means it contains garbage values unless explicitly initialized.
        calloc() initializes the allocated memory to zero, making it useful for arrays or buffers that need to be cleared before use.

    Performance:
        calloc() may be slightly slower than malloc() because it initializes the memory block.
        However, the difference in performance is usually negligible for small allocations.

    Use Cases:
        malloc() is commonly used when initialization of memory is not required, or when performance is a concern.
        calloc() is preferred when allocating memory for arrays or buffers that need to be zero-initialized.

In summary: malloc() is more general-purpose and faster, while calloc() is specifically designed for zero-initialized memory allocation. 
Use malloc() when you don't need initialization, and use calloc() when you do.

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Using malloc()
    int *ptr_malloc = (int*)malloc(5 * sizeof(int));
    if (ptr_malloc == NULL) {
        printf("Memory allocation failed for malloc().\n");
        return 1;
    }

    // Initialize values with malloc()
    for (int i = 0; i < 5; i++) {
        ptr_malloc[i] = i + 1;
    }

    // Print values allocated with malloc()
    printf("Using malloc():\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr_malloc[i]);
    }
    printf("\n");

    // Free allocated memory for malloc()
    free(ptr_malloc);


    // Using calloc()
    int *ptr_calloc = (int*)calloc(5, sizeof(int));
    if (ptr_calloc == NULL) {
        printf("Memory allocation failed for calloc().\n");
        return 1;
    }

    // No need to initialize values with calloc()

    // Print values allocated with calloc()
    printf("Using calloc():\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr_calloc[i]);
    }
    printf("\n");

    // Free allocated memory for calloc()
    free(ptr_calloc);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// 1. Declaring and Using Pointers
int basicPointer() {
    int x = 10;
    int *p; // point to an integer
    p = &x; // assign the address of x to p
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", &x);
    printf("Value of p: %p\n", p);
    printf("Value pointed by p: %d\n", *p);
    return 0;
}
// 2. Pointer Arithmetic
int poerMath() {
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr; // point to first element of the array
    printf("Value at p: %d\n", *p); // value at the address pointed by p
    p++; // move to next element
    printf("Value at p after increment: %d\n", *p);
    return 0;
}
// 3. Pointers to Functions
void printMessage() {
    printf("Hello, World!\n");
}
int func_main() {
    void (*ptr)(void) = printMessage; // point to the function
    ptr(); // call function through pointer
    return 0;
}
// 4. Dynamic Memory Allocation Using Pointers
int dynamicMemoryAllocation() {
    int *p = (int*)malloc(sizeof(int)); // allocate memory for an integer
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    *p = 10; // assign value to the allocated memory
    printf("Value at allocated memory: %d\n", *p);
    free(p); // free allocated memory
    return 0;
}
int main() {
    basicPointer();
    poerMath();
    func_main();
    dynamicMemoryAllocation();
    return 0;
}
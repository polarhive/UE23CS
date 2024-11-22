#include <stdlib.h>
#include <stdio.h>
void vulnerable_function()
{
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    *ptr = 10;
    printf("Value before free: %d\n", *ptr);
    free(ptr);
    printf("Value after first free: %d\n", *ptr);
    free(ptr);
    printf("Value after second free: %d\n", *ptr);
}
int main()
{
    vulnerable_function();
    return 0;
}

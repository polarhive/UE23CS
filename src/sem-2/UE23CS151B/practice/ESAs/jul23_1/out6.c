#include <stdio.h>
#include <stddef.h>

union A
{
    int x;
    float y;
    char z;
};

int main()
{
    printf("%lu", offsetof(union A, z));
}

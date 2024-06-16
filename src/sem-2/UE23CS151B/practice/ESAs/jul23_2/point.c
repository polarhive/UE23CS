#include <stdio.h>

int main() {
    int num = 10;
    int *p;
    p = &num; 

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value of *p: %d\n", *p);
    printf("Address stored in p: %p\n", p);

    return 0;
}

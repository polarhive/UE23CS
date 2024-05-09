#include <stdio.h>
int main() {
    int a[] = {10, 20, 30, 40, 50};
    int sum=0;
    for (int i = 0; i < (sizeof(a[0])); i++) {
        printf("%s: %d\n",  "at element", a[i]);
        printf("%s: %d \n", "sum", sum+=a[i]);
    }
    return 0;
}

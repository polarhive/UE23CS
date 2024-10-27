#include <stdio.h>
int main() {
    int a[] = {1, 5, 2, 5, 2, 5, 5};
    float b = 0;
    for (int i = 0; i < 6; i++) {
        b += a[i];
    }
    b = b / 6.0; 
    printf("%.2f\n", b);
    return 0;
}

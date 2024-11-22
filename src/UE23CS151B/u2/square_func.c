#include <stdio.h>
#include <stdlib.h>
int a;
int sq(int a) {
    return a*a;
}

int main() {
    printf("%s\n", "enter a number:");
    scanf("%d", &a);
    return printf("%d\n", sq(a));
}

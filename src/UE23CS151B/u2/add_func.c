#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

void output(int sum) {
    printf("%d\n", sum);
}

void input() {
    int a, b;
    printf("%s\n", "enter 2 numbers:");
    scanf("%d %d", &a, &b);
    int sum = add(a, b);
    output(sum);
}

int main() {
    input();
    return 0;
}

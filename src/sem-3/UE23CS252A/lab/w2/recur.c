#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void generatePermutations(char *s, int l, int r) {
    if (l == r) {
        printf("%s\n", s);
    } else {
        for (int i = l; i <= r; i++) {
            swap((s + l), (s + i));
            generatePermutations(s, l + 1, r);
            swap((s + l), (s + i));
        }
    }
}

int main() {
    char s[20];
    scanf("%s", s);

    int len = strlen(s);

    generatePermutations(s, 0, len - 1);

    return 0;
}

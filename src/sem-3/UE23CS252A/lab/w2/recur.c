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

    // Sort the string in ascending order
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] > s[j]) {
                swap(&s[i], &s[j]);
            }
        }
    }

    generatePermutations(s, 0, len - 1);

    return 0;
}

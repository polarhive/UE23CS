/*In the kingdom of Lumeria, scholars of the Arcane Library guard an ancient
 * magic book containing powerful spells. However, the spells can only be cast
 * if the correct word permutation is spoken in a precise order.

The book’s guardian, provides a challenge to any who wish to access the spells:
"You must determine the next lexicographic permutation of the given magical
word. Only then shall the secrets be revealed!"

Can find the next valid permutation of a given word? If the word itself is the
last permutation the spell is “No Successor”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *str, int start, int end) {
    while (start < end) {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}

char* nextPermutation(char *str) {
    int n = strlen(str);
    int i = n - 2;

    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }
    if (i < 0) {
        return "No Successor";
    }

    int j = n - 1;
    while (str[j] <= str[i]) {
        j--;
    }
    swap(&str[i], &str[j]);

    reverse(str, i + 1, n - 1);
    return str;
}

// Driver function
int main() {
    char str[11];  // Given constraint: max length = 10

    scanf("%s", str);

    char *nextPerm = nextPermutation(str);
    printf("%s\n", nextPerm);

    return 0;
}


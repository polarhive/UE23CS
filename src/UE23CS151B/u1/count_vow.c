#include<stdio.h>

int main() {
    char c = 'a';
    char s[100]; 
    printf("Input string: ");
    scanf("%s", s);

    int i = 0;
    int j = 0;

    while (s[j] != '\0') { 
        c = s[j]; 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            i++; 
        }
        j++; 
    }

    printf("Number of vowels: %d\n", i); 
    return 0;
}

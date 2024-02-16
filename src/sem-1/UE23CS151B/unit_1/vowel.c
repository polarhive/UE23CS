#include<stdio.h>
int main()
{
    char c;
    printf("Input a char: ");
    scanf("%c", &c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') printf("%s", "vowel\n");
    else printf("%s", "not a vowel\n");
    return 0;
}

#include <stdio.h>

void my_strcat(char* a, char* b);
int main() {
    char str1[20] = "Hello, ";
    char str2[] = "world!";

    printf("Before concatenation:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    my_strcat(str1, str2);
    printf("\nAfter concatenation:\n");
    printf("str1: %s\n", str1);
}

void my_strcat(char* a, char* b)
{
    while (*a)
    {
        a++; // move to the end
    }
    while (*b)
    {
        *a = *b; 
        a++;
        b++;
    }
    *a = '\0';
}

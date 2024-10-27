#include <stdio.h>

void my_strcat(char *dest, const char *src)
{
    // Find the end of the destination string
    while (*dest)
    {
        dest++;
    }
    // Copy the source string to the end of the destination string
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    // Null-terminate the resulting string
    *dest = '\0';
}

int main()
{
    char str1[100], str2[100];

    printf("Enter str1: ");
    fgets(str1, sizeof(str1), stdin);
    // Remove newline character if present
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter str2: ");
    fgets(str2, sizeof(str2), stdin);
    // Remove newline character if present
    str2[strcspn(str2, "\n")] = '\0';

    my_strcat(str1, str2);

    printf("str1 is %s and str2 is %s\n", str1, str2);
    return 0;
}

#include <stdio.h>
int main()
{
    char str[] = "BEST";
    int i;
    for (i = 0; str[i]; i++)
        printf("%c %c %c %c\n", str[i], *(str + i), *(i + str), i[str] + 2);
}

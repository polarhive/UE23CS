#include<stdio.h>
int main()
{
    printf("enter a character (getchar): ");
    char ch = getchar();
    putchar(ch);

    printf("enter a character (getc): ");
    ch=getc(stdin);
    putc(ch,stdout);

    printf("enter a character (getch)");
    ch = getch();
    putch(ch);

}

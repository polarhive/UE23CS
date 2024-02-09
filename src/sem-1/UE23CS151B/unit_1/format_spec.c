/* 
 * format specifiers
 * printf()
 * sends formatted output to STDOUT
 * output is controlled by the first argument
*/

#include<stdio.h>
int main()
{
    int a = 10;
    double d = 89.453667;
    char p = 'c';
    int e = 0113; //octal
    int h = 0xA; //hexadecimal
    int i = 0b111; //binary
    printf("%d\n", a);
    printf("%o\n", e);
    printf("%x\n", e);
    printf("%X\n", e);
    printf("%d\n", h);
    printf("%d\n", i);
    return 0;
}

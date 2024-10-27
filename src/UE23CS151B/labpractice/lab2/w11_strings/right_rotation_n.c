// You are given a string. Perform a Right Rotation of the given string by a number n.
// Right rotation of the string is performed by moving the last character of the string to the
// first and shifting the remaining characters of the string to the right by 1 shift.
// By repeating this procedure n times we obtain the right rotated string which is rotated n
// times.
// Here is the example of right rotation of string:
// String: Hello
// Number of rotations: 2
// Rotated String: loHel

#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    char s[20];
    scanf("%d\n", &n);
    scanf("%[^\n]%*c", s);
    int len = strlen(s);
    for (int i = 0; i < n; i++)
    {
        char last = s[len - 1];
        for (int i = len - 2; i >= 0; i--)
        {
            s[i + 1] = s[i];
        }
        s[0] = last;
    }
    printf("%s", s);
    return 0;
}
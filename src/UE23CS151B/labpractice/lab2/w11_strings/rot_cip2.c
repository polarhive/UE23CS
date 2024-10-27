// A ROT Cipher is a data encryption technique in which a given message is encrypted by
// shifting the letters in the given message by a certain number known as key. Here is an
// example of data encryption by ROT Cipher:
// Original Message: abc
// Key:25
// Encrypted message: zab
// Write a program to read the message and the key value. Design a solution which prints the
// encrypted message using ROT Cipher technique. (NOTE: Don’t use any String built-in
// functions).

#include <stdio.h>
int main()
{
    int n;
    char s[20];
    scanf("%[^\n]s", s);
    scanf("%d", &n);
    for (int i = 0; s[i] != '\0'; i++)

    {
        if (s[i] >= 97 && s[i] <= 122)
            s[i] = (s[i] - 97 + n) % 26 + 97;
        else if (s[i] >= 65 && s[i] <= 90)
            s[i] = (s[i] - 65 + n) % 26 + 65;
    }
    printf("%s", s);
    return 0;
}
// A ROT Cipher is a data encryption technique in which a given message is encrypted by
// shifting the letters in the given message by a certain number known as key.
// Each character in the given word is shifted by the given key. For example if the key is 7
// then a is replaced with h as h is 7 characters after a and b is replaced with i and so on. If
// the character is z it is replaced with g.
// The string which is obtained by shifting all the characters is the encrypted string.
// Here is an example of data encryption by ROT Cipher:
// Original Message: abc
// Key:25
// Encrypted message: zab

#include <stdio.h>
#include <string.h>
int main()

{
    int n;
    char s[20];
    scanf("%d\n", &n);
    scanf("%[^\n]%*c", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
            s[i] = (s[i] - 97 + n) % 26 + 97;
        else if (s[i] >= 65 && s[i] <= 90)
            s[i] = (s[i] - 65 + n) % 26 + 65;
    }
    printf("%s", s);
    return 0;
}
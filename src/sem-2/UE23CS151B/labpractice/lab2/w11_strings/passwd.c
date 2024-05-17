// Write a C program that prompts the user to input a password as a string and evaluates
// its strength based on the following criteria: must include at least (1) one lowercase
// letter (a-z), (2) one uppercase letter (A-Z), (3) one digit [0-9], and (4) one special
// character from the set {!, @, #, $, %, &, *} (5) the password must be at least 8 characters
// long . The program should categorize the password as follows:
// Strong: meets all 5 criteria
// Moderate: meets criterias 1,2,3,5 but not 4
// Weak: Does not meet the rest of the specified criterias.
// (NOTE: You are allowed to use strlen( ) function to find the length of the string , if
// required)

#include <stdio.h>
#include <string.h>

int main()
{
    char password[100];
    int length, hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;
    scanf("%s", password);
    length = strlen(password);
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            hasLower = 1;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            hasUpper = 1;
        else if (password[i] >= '0' && password[i] <= '9')
            hasDigit = 1;
        else if (password[i] == '!' || password[i] == '@' || password[i] == '#' ||
                 password[i] == '$' || password[i] == '%' || password[i] == '&' ||
                 password[i] == '*')
            hasSpecial = 1;
    }
    if (hasLower && hasUpper && hasDigit && hasSpecial && length >= 8)
        printf("Strong\n");
    else if (hasLower && hasUpper && length >= 8)
        printf("Moderate\n");
    else
    {
        printf("Weak\n");
    }

    return 0;
}
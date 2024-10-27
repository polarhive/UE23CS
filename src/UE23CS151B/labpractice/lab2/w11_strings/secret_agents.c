// Aastha and Ashish are secret agents who need to exchange messages securely. To
// enhance the security of their messages, they decide to encode the messages using a
// simple algorithm. The algorithm involves replacing each character in the message with
// its ASCII code + 2.
// Write a C program to encode messages based on this algorithm. The program should
// read the message (can include spaces) and the program should print each character in
// the message with its ASCII Code+2.

#include <stdio.h>
int main()
{
    char message[100];

    scanf("%[^\n]", message);
    for (int i = 0; message[i] != '\0'; i++)
    {
        if (message[i] != ' ')
        {
            printf("%d ", (int)message[i] + 2);
        }
        else
        {
            printf("34 ");
        }
    }
    return 0;
}
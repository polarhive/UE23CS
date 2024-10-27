#include<stdio.h>
int main()
{
    char c;
    int a;
    int b;

    printf("input operation:\n +\n -\n *\n /\n\n");
    printf("%s", "-------------\n");
    scanf("%c", &c);

    printf("input 'a' and 'b':\n");
    scanf("%d", &a);
    scanf("%d", &b);

    switch (c) {
    case '+': 
            printf("%d", a+b);
            break;
    case '-': 
            printf("%d", a-b);
            break;
    case '*': 
            printf("%d", a*b);
            break;
    case '/': 
            printf("%f", (float)a/(float)b);
            break;

    default: printf("%s", "error\n");
             break;
    }

    return 0;
}

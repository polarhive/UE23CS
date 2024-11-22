#include<stdio.h>
int main()
{
    int c;
    printf("Input a day: 1\n 2\n 3\n 4\n 5\n 6\n 7\ ");
    scanf("%d", &c);
    switch (c) {
    case 1: 
            printf("%s", "Monday \n");
            break;
    case 2: 
            printf("%s", "Tuesday\n");
            break;
    case 3: 
            printf("%s", "Wednesday\n");
            break;
    case 4: 
            printf("%s", "Thursday\n");
            break;
    case 5: 
            printf("%s", "Friday\n");
            break;
    case 6: 
            printf("%s", "Saturday\n");
            break;
    case 7: 
            printf("%s", "Sunday\n");
            break;

    default: printf("%s", "error\n");
             break;
    }

    return 0;
}

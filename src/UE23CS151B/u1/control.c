#include<stdio.h>
int main()
{
    int time = 22;
    if (time < 10) printf("%s", "morning");
    else if (time > 12) printf("%s", "noon");
    else if (time > 18) printf("%s", "evening");
    else if (time > 21) printf("%s", "sleepytime");
    
    return 0;
}

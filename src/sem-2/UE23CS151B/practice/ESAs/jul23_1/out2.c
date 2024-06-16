#include <stdio.h>
#include<string.h>
int main()
{
    char line[100]="PESU,EC,RR";
    printf("%s ",strtok(line,","));
    printf("%s ",strtok(NULL,","));
    printf("%s ",strtok(line,","));
}

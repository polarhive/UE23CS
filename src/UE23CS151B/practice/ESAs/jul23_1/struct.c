// produce the output 1001 and XYZ separated by a tab space.

#include <stdio.h>
#include <string.h>

struct Student
{
    int roll_no;
    char name[100];
};

int main()
{
    struct Student s;
    s.roll_no = 1001;
    strcpy(s.name, "XYZ");
    printf("%d\t%s\n", s.roll_no, s.name);
}

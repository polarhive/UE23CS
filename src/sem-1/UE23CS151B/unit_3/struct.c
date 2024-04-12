#include <stdio.h>
struct MyStruct {
    int rollno;
    char name[25];
    int marks;
};
int main() {
    struct MyStruct s1 = { .marks = 25, .name={'m', 'e', '\0'} };
    
    printf("Roll No: %d\n", s1.rollno);
    printf("Name: %s\n", s1.name);
    printf("Marks: %d\n", s1.marks);
    
    return 0;
}

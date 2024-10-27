// Create a structure called ‘Student’ with the following members:
// name: Represents the student's name.
// id_numbers: A nested structure representing the student's identification numbers, with
// members SRN and PRN.
// sectionr: Represents the student's section..
// marks: An integer array representing the student's marks for one subject. The array
// should store marks obtained in PSWC subject in the following order: ISA 1(out of 40),
// ISA 2(out of 40), Lab(out of 20), and ESA(out of 100).
// Write a C program that accomplishes the following tasks:
// 1. Implement a function to read details of a student from the user.
// 2. Implement a function to display all the details entered by the user.
// 3. Implement a function to calculate the final marks obtained in the subject based on
// the formula: Final mark = (Reduced (ISA 1 + ISA 2 + Lab+ESA)) ,where the ISA 1, ISA
// 2, lab and ESA marks are reduced by half, i.e , ISA marks are scaled down to 20
// Lab marks are scaled down to 10, ESA marks scaled down to 50.

#include <stdio.h>
struct IDNumbers
{
    char SRN[20];
    char PRN[20];
};
struct Student
{
    char name[50];
    struct IDNumbers id;
    char sec;
    int marks[4]; // Marks for ISA 1, ISA 2, Lab, ESA
};

struct Student read_student_details()
{
    struct Student student;
    printf("Enter student name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter student SRN: ");
    scanf(" %[^\n]", student.id.SRN);
    printf("Enter student PRN: ");
    scanf(" %[^\n]", student.id.PRN);
    printf("Enter student section: ");
    scanf(" %c", &student.sec); // Added space before %c
    printf("Enter marks for ISA 1, ISA 2, Lab, ESA: ");

    scanf("%d %d %d %d", &student.marks[0], &student.marks[1],
          &student.marks[2], &student.marks[3]);
    return student;
}
void display_student_details(struct Student student)
{
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.name);
    printf("SRN: %s\n", student.id.SRN);
    printf("PRN: %s\n", student.id.PRN);
    printf("Section: %c\n", student.sec);
    printf("Marks for ISA 1: %d\n", student.marks[0]);
    printf("Marks for ISA 2: %d\n", student.marks[1]);
    printf("Marks for Lab: %d\n", student.marks[2]);
    printf("Marks for ESA: %d\n", student.marks[3]);
}
int calculate_final_marks(struct Student student)
{
    int total_marks = student.marks[0] / 2 + student.marks[1] / 2 +
                      student.marks[2] / 2 + student.marks[3] / 2;
    return total_marks;
}
int main()
{

    struct Student student = read_student_details();
    display_student_details(student);
    int final_marks = calculate_final_marks(student);
    printf("Final Marks: %d\n", final_marks);
    return 0;
}
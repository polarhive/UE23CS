#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define MAX_DOB_LENGTH 15
#define MAX_SCHEDULE_LENGTH 50
#define MAX_DATE_LENGTH 15
#define MAX_TYPE_LENGTH 20

#define MAX_COURSES 50
#define MAX_ENROLLMENTS 500
#define MAX_STUDENTS 100
#define MAX_TRANSACTIONS 1000

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phoneNumber[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char dob[MAX_DOB_LENGTH];
} Student;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char instructor[MAX_NAME_LENGTH];
    char schedule[MAX_SCHEDULE_LENGTH];
    int credits;
} Course;

typedef struct {
    int id;
    int studentId;
    int courseId;
    char date[MAX_DATE_LENGTH];
} Enrollment;

typedef struct {
    int id;
    int studentId;
    char type[MAX_TYPE_LENGTH];
    float amount;
    char date[MAX_DATE_LENGTH];
} Transaction;

Student students[MAX_STUDENTS];
Course courses[MAX_COURSES];
Enrollment enrollments[MAX_ENROLLMENTS];
Transaction transactions[MAX_TRANSACTIONS];

int student_count = 0;
int course_count = 0;
int enrollment_count = 0;
int transaction_count = 0;

void addStudent() {
    if (student_count < MAX_STUDENTS) {
        printf("Enter Student Details:\n");
        printf("Student ID: ");
        scanf("%d", &students[student_count].id);
        printf("Name: ");
        scanf("%s", students[student_count].name);
        printf("Address: ");
        scanf("%s", students[student_count].address);
        printf("Phone Number: ");
        scanf("%s", students[student_count].phoneNumber);
        printf("Email: ");
        scanf("%s", students[student_count].email);
        printf("Date of Birth: ");
        scanf("%s", students[student_count].dob);
        student_count++;
        printf("Student Details added\n");
    } else {
        printf("No more space left to add a student\n");
    }
}

void updateStudent() {
    int id, i;
    printf("Enter the ID of the Student: ");
    scanf("%d", &id);
    for (i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            printf("Enter the details to update:\n");
            printf("Name: ");
            scanf("%s", students[i].name);
            printf("Address: ");
            scanf("%s", students[i].address);
            printf("Phone Number: ");
            scanf("%s", students[i].phoneNumber);
            printf("Email: ");
            scanf("%s", students[i].email);
            printf("Date of Birth: ");
            scanf("%s", students[i].dob);
            printf("Student Details Updated.\n");
            return;
        }
    }
    printf("Student ID Is Not Valid.\n");
}

void deleteStudent() {
    int id, i, found = 0;
    printf("Enter The ID Of The Student: ");
    scanf("%d", &id);
    for (i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student Details Deleted.\n");
            break;
        }
    }
    if (!found)
        printf("Student ID Is Not Valid.\n");
}

void displayStudents() {
    if (student_count == 0) {
        printf("No Students Are There.\n");
        return;
    }
    printf("Student Details:\n");
    printf("ID\tName\tAddress\tPH.Number\tMail\tDOB\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d\t%s\t%s\t%s\t%s\t%s\n", students[i].id, students[i].name, students[i].address,
               students[i].phoneNumber, students[i].email, students[i].dob);
    }
}

void addCourse() {
    if (course_count < MAX_COURSES) {
        printf("Enter Course Details:\n");
        printf("Course ID: ");
        scanf("%d", &courses[course_count].id);
        printf("Course Name: ");
        scanf("%s", courses[course_count].name);
        printf("Instructor: ");
        scanf("%s", courses[course_count].instructor);
        printf("Schedule: ");
        scanf("%s", courses[course_count].schedule);
        printf("Credits: ");
        scanf("%d", &courses[course_count].credits);
        course_count++;
        printf("Course Added Successfully.\n");
    } else {
        printf("No More Space Left To Add Course\n");
    }
}

void updateCourse() {
    int id, i;
    printf("Enter The ID Of The Course: ");
    scanf("%d", &id);
    for (i = 0; i < course_count; i++) {
        if (courses[i].id == id) {
            printf("Enter Details To Update: ");
            printf("Course Name: ");
            scanf("%s", courses[i].name);
            printf("Instructor: ");
            scanf("%s", courses[i].instructor);
            printf("Schedule: ");
            scanf("%s", courses[i].schedule);
            printf("Credits: ");
            scanf("%d", &courses[i].credits);
            printf("Course Details Updated.\n");
            return;
        }
    }
    printf("Course ID Is Not Valid\n");
}

void deleteCourse() {
    int id, i, found = 0;
    printf("Enter The ID Of The Course: ");
    scanf("%d", &id);
    for (i = 0; i < course_count; i++) {
        if (courses[i].id == id) {
            found = 1;
            for (int j = i; j < course_count - 1; j++) {
                courses[j] = courses[j + 1];
            }
            course_count--;
            printf("Course Details Deleted.\n");
            break;
        }
    }
    if (!found)
        printf("Course ID Is Not Valid.\n");
}

void displayCourses() {
    if (course_count == 0) {
        printf("No Courses Are There.\n");
        return;
    }
    printf("Course Details:\n");
    printf("ID\tName\tInstructor\tSchedule\tCredits\n");
    for (int i = 0; i < course_count; i++) {
        printf("%d\t%s\t%s\t%s\t%d\n", courses[i].id, courses[i].name, courses[i].instructor,
               courses[i].schedule, courses[i].credits);
    }
}

void enrollStudent() {
    if (enrollment_count < MAX_ENROLLMENTS) {
        printf("Enter Enrollment Details:\n");
        printf("Enrollment ID: ");
        scanf("%d", &enrollments[enrollment_count].id);
        printf("Student ID: ");
        scanf("%d", &enrollments[enrollment_count].studentId);
        printf("Course ID: ");
        scanf("%d", &enrollments[enrollment_count].courseId);
        printf("Enrollment Date: ");
        scanf("%s", enrollments[enrollment_count].date);
        enrollment_count++;
        printf("Student Enrolled.\n");
    } else {
        printf("No More Space Left For Enrollment\n");
    }
}

void withdrawStudent() {
    int id, i, found = 0;
    printf("Enter ID Of The Enrollment Student: ");
    scanf("%d", &id);
    for (i = 0; i < enrollment_count; i++) {
        if (enrollments[i].id == id) {
            found = 1;
            for (int j = i; j < enrollment_count - 1; j++) {
                enrollments[j] = enrollments[j + 1];
            }
            enrollment_count--;
            printf("Enrollment ID Is Withdrawn.\n");
            break;
        }
    }
    if (!found)
        printf("Enrollment ID Is Not Valid.\n");
}

void displayEnrollments() {
    if (enrollment_count == 0) {
        printf("No Enrollments Are There.\n");
        return;
    }
    printf("Enrollment Details:\n");
    printf("ID\tStudent ID\tCourse ID\tEnrollment Date\n");
    for (int i = 0; i < enrollment_count; i++) {
        printf("%d\t%d\t\t%d\t\t%s\n", enrollments[i].id, enrollments[i].studentId,
               enrollments[i].courseId, enrollments[i].date);
    }
}

void addTransaction() {
    if (transaction_count < MAX_TRANSACTIONS) {
        printf("Enter Transaction Details:\n");
        printf("Transaction ID: ");
        scanf("%d", &transactions[transaction_count].id);
        printf("Student ID: ");
        scanf("%d", &transactions[transaction_count].studentId);
        printf("Transaction Type: ");
        scanf("%s", transactions[transaction_count].type);
        printf("Transaction Amount: ");
        scanf("%f", &transactions[transaction_count].amount);
        printf("Transaction Date: ");
        scanf("%s", transactions[transaction_count].date);
        transaction_count++;
        printf("Transaction Details Added.\n");
    } else {
        printf("No More Space Left To Add Transaction :( .\n");
    }
}

void displayTransactions() {
    if (transaction_count == 0) {
        printf("No Transactions Are There.\n");
        return;
    }
    printf("Transaction Details:\n");
    printf("ID\tStudent ID\tType\tAmount\tDate\n");
    for (int i = 0; i < transaction_count; i++) {
        printf("%d\t%d\t\t%s\t%.2f\t%s\n", transactions[i].id, transactions[i].studentId,
               transactions[i].type, transactions[i].amount, transactions[i].date);
    }
}

int main() {
    int choice;

    while (1) {
        printf("PES Student Management System\n");
        printf("-----------------------------\n");
        printf("1: Student Details\n");
        printf("2: Course Details\n");
        printf("3: Enrollment\n");
        printf("4: Transactions\n");
        printf("5: Exit\n");
        printf("-------\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nStudent Details\n");
                printf("1: Add Student\n");
                printf("2: Update Student Details\n");
                printf("3: Delete Student Details\n");
                printf("4: Display Students\n");
                printf("Enter your choice:\n");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        addStudent();
                        break;
                    case 2:
                        updateStudent();
                        break;
                    case 3:
                        deleteStudent();
                        break;
                    case 4:
                        displayStudents();
                        break;
                    default:
                        printf("Please enter a valid choice\n");
                }
                break;
            case 2:
                printf("\nCourse Details\n");
                printf("1: Add Course\n");
                printf("2: Update Course Details\n");
                printf("3: Delete Course Details\n");
                printf("4: Display Courses\n");
                printf("Enter your choice:\n");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        addCourse();
                        break;
                    case 2:
                        updateCourse();
                        break;
                    case 3:
                        deleteCourse();
                        break;
                    case 4:
                        displayCourses();
                        break;
                    default:
                        printf("Please enter a valid choice\n");
                }
                break;
            case 3:
                printf("\nEnrollment\n");
                printf("1: Enroll Student\n");
                printf("2: Withdraw Student\n");
                printf("3: Display Enrollments\n");
                printf("Enter your choice:\n");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        enrollStudent();
                        break;
                    case 2:
                        withdrawStudent();
                        break;
                    case 3:
                        displayEnrollments();
                        break;
                    default:
                        printf("Please enter a valid choice\n");
                }
                break;
            case 4:
                printf("\nTransactions\n");
                printf("1: Add Transaction\n");
                printf("2: Display Transactions\n");
                printf("Enter your choice:\n");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        addTransaction();
                        break;
                    case 2:
                        displayTransactions();
                        break;
                    default:
                        printf("Please enter a valid choice\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Please enter a valid choice\n");
        }
    }
    return 0;
}

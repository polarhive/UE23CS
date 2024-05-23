#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATE_LENGTH 20
#define MAX_COURSES 50
#define MAX_ENROLLMENTS 500
#define MAX_STUDENTS 100
#define MAX_TRANSACTIONS 1000

int course_count = 0;
int course_credits[MAX_COURSES];
int course_ids[MAX_COURSES];
char course_instructors[MAX_COURSES][50];
char course_names[MAX_COURSES][50];
char course_schedules[MAX_COURSES][50];

int enrollment_count = 0;
int enrollment_course_ids[MAX_ENROLLMENTS];
int enrollment_ids[MAX_ENROLLMENTS];
int enrollment_student_ids[MAX_ENROLLMENTS];
char enrollment_dates[MAX_ENROLLMENTS][15];

int student_count = 0;
int student_ids[MAX_STUDENTS];
char student_phone_numbers[MAX_STUDENTS][15];
char student_addresses[MAX_STUDENTS][100];
char student_dobs[MAX_STUDENTS][15];
char student_emails[MAX_STUDENTS][50];
char student_names[MAX_STUDENTS][50];

int transaction_count = 0;
int transaction_ids[MAX_TRANSACTIONS];
int transaction_student_ids[MAX_TRANSACTIONS];
char transaction_dates[MAX_TRANSACTIONS][15];
char transaction_types[MAX_TRANSACTIONS][20];
float transaction_amounts[MAX_TRANSACTIONS];

void addStudent() {
    if (student_count < MAX_STUDENTS) {
        printf("Enter Student Details:\n");
        printf("Student ID: ");
        scanf("%d", &student_ids[student_count]);
        printf("Name: ");
        scanf("%s", student_names[student_count]);
        printf("Address: ");
        scanf("%s", student_addresses[student_count]);
        printf("Phone Number: ");
        scanf("%s", student_phone_numbers[student_count]);
        printf("Email: ");
        scanf("%s", student_emails[student_count]);
        printf("Date of Birth: ");
        scanf("%s", student_dobs[student_count]);
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
        if (student_ids[i] == id) {
            printf("Enter the details to update:\n");
            printf("Name: ");
            scanf("%s", student_names[i]);
            printf("Address: ");
            scanf("%s", student_addresses[i]);
            printf("Phone Number: ");
            scanf("%s", student_phone_numbers[i]);
            printf("Email: ");
            scanf("%s", student_emails[i]);
            printf("Date of Birth: ");
            scanf("%s", student_dobs[i]);
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
        if (student_ids[i] == id) {
            found = 1;
            for (int j = i; j < student_count - 1; j++) {
                student_ids[j] = student_ids[j + 1];
                student_names[j][0] = student_names[j + 1][0];
                student_addresses[j][0] = student_addresses[j + 1][0];
                student_phone_numbers[j][0] = student_phone_numbers[j + 1][0];
                student_emails[j][0] = student_emails[j + 1][0];
                student_dobs[j][0] = student_dobs[j + 1][0];
            }
            student_ids[student_count - 1] = 0;
            student_names[student_count - 1][0] = '\0';
            student_addresses[student_count - 1][0] = '\0';
            student_phone_numbers[student_count - 1][0] = '\0';
            student_emails[student_count - 1][0] = '\0';
            student_dobs[student_count - 1][0] = '\0';
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
        printf("%d\t%s\t%s\t%s\t%s\t%s\n", student_ids[i], student_names[i], student_addresses[i],
               student_phone_numbers[i], student_emails[i], student_dobs[i]);
    }
}

void addCourse() {
    if (course_count < MAX_COURSES) {
        printf("Enter Course Details:\n");
        printf("Course ID: ");
        scanf("%d", &course_ids[course_count]);
        printf("Course Name: ");
        scanf("%s", course_names[course_count]);
        printf("Instructor: ");
        scanf("%s", course_instructors[course_count]);
        printf("Schedule: ");
        scanf("%s", course_schedules[course_count]);
        printf("Credits: ");
        scanf("%d", &course_credits[course_count]);
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
        if (course_ids[i] == id) {
            printf("Enter Details To Update: ");
            printf("Course Name: ");
            scanf("%s", course_names[i]);
            printf("Instructor: ");
            scanf("%s", course_instructors[i]);
            printf("Schedule: ");
            scanf("%s", course_schedules[i]);
            printf("Credits: ");
            scanf("%d", &course_credits[i]);
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
        if (course_ids[i] == id) {
            found = 1;
            for (int j = i; j < course_count - 1; j++) {
                course_ids[j] = course_ids[j + 1];
                strcpy(course_names[j], course_names[j + 1]);
                strcpy(course_instructors[j], course_instructors[j + 1]);
                strcpy(course_schedules[j], course_schedules[j + 1]);
                course_credits[j] = course_credits[j + 1];
            }
            course_count--;
            printf("Course Details Deleted.\n");
            break;
        }
    }
    if (!found)
        printf("Course ID Is Not Valid.");
}

void displayCourses() {
    if (course_count == 0) {
        printf("No Courses Are There.\n");
        return;
    }
    printf("Course Details:\n");
    printf("ID\tName\tInstructor\tSchedule\tCredits\n");
    for (int i = 0; i < course_count; i++) {
        printf("%d\t%s\t%s\t%s\t%d\n", course_ids[i], course_names[i], course_instructors[i],
               course_schedules[i], course_credits[i]);
    }
}


void enrollStudent() {
    if (enrollment_count < MAX_ENROLLMENTS) {
        printf("Enter Enrollment Details:\n");
        printf("Enrollment ID: ");
        scanf("%d", &enrollment_ids[enrollment_count]);
        printf("Student ID: ");
        scanf("%d", &enrollment_student_ids[enrollment_count]);
        printf("Course ID: ");
        scanf("%d", &enrollment_course_ids[enrollment_count]);
        printf("Enrollment Date: ");
        scanf("%s", enrollment_dates[enrollment_count]);
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
        if (enrollment_ids[i] == id) {
            found = 1;
            for (int j = i; j < enrollment_count - 1; j++) {
                enrollment_ids[j] = enrollment_ids[j + 1];
                enrollment_student_ids[j] = enrollment_student_ids[j + 1];
                enrollment_course_ids[j] = enrollment_course_ids[j + 1];
                for (int k = 0; k < DATE_LENGTH; k++) {
                    enrollment_dates[j][k] = enrollment_dates[j + 1][k];
                }
            }
            enrollment_ids[enrollment_count - 1] = 0;
            enrollment_student_ids[enrollment_count - 1] = 0;
            enrollment_course_ids[enrollment_count - 1] = 0;
            for (int k = 0; k < DATE_LENGTH; k++) {
                enrollment_dates[enrollment_count - 1][k] = '\0';
            }
            enrollment_count--;
            printf("Enrollment ID Is Withdrawn.\n");
            break;
        }
    }
    if (!found)
        printf("Enrollment ID Is Not Valid.");
}

void displayEnrollments() {
    if (enrollment_count == 0) {
        printf("No Enrollments Are There.\n");
        return;
    }
    printf("Enrollment Details:\n");
    printf("ID\tStudent ID\tCourse ID\tEnrollment Date\n");
    for (int i = 0; i < enrollment_count; i++) {
        printf("%d\t%d\t\t%d\t\t%s\n", enrollment_ids[i], enrollment_student_ids[i],
               enrollment_course_ids[i], enrollment_dates[i]);
    }
}


void addTransaction() {
    if (transaction_count < MAX_TRANSACTIONS) {
        printf("Enter Transaction Details:\n");
        printf("Transaction ID: ");
        scanf("%d", &transaction_ids[transaction_count]);
        printf("Student ID: ");
        scanf("%d", &transaction_student_ids[transaction_count]);
        printf("Transaction Type: ");
        scanf("%s", transaction_types[transaction_count]);
        printf("Transaction Amount: ");
        scanf("%f", &transaction_amounts[transaction_count]);
        printf("Transaction Date: ");
        scanf("%s", transaction_dates[transaction_count]);
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
        printf("%d\t%d\t\t%s\t%.2f\t%s\n", transaction_ids[i], transaction_student_ids[i],
               transaction_types[i], transaction_amounts[i], transaction_dates[i]);
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

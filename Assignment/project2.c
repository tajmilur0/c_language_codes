#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 10

// Structure to store student details
struct Student {
    char name[50];
    int roll;
    char semester[20];
    char registrationNo[20];
    int numCourses;
    char courseCode[MAX_COURSES][10];
    char courseName[MAX_COURSES][50];
    int courseCredit[MAX_COURSES];
    float courseMark[MAX_COURSES];
    float cgpa;
    char cgpaGrade;
};

// Function to get the grade based on percentage
char getGrade(float percentage) {
    if (percentage >= 80)
        return 'A';
    else if (percentage >= 75)
        return 'A';
    else if (percentage >= 70)
        return 'A';
    else if (percentage >= 65)
        return 'B';
    else if (percentage >= 60)
        return 'B';
    else if (percentage >= 55)
        return 'B';
    else if (percentage >= 50)
        return 'C';
    else if (percentage >= 45)
        return 'C';
    else if (percentage >= 40)
        return 'D';
    else
        return 'F';
}

// Function to get the CGPA grade based on CGPA
char getCGPAGrade(float cgpa) {
    if (cgpa >= 3.75)
        return 'A';
    else if (cgpa >= 3.50)
        return 'A';
    else if (cgpa >= 3.25)
        return 'A';
    else if (cgpa >= 3.00)
        return 'B';
    else if (cgpa >= 2.75)
        return 'B';
    else if (cgpa >= 2.50)
        return 'B';
    else if (cgpa >= 2.00)
        return 'C';
    else
        return 'F';
}

// Function to calculate CGPA
float calculateCGPA(int numCourses, int courseCredit[], float courseMark[]) {
    float totalCredit = 0.0, totalGradePoint = 0.0;

    // Calculate total credit
    for (int i = 0; i < numCourses; i++) {
        totalCredit += courseCredit[i];
    }

    // Calculate total grade point
    for (int i = 0; i < numCourses; i++) {
        float percentage = (courseMark[i] / 100) * 100;
        char grade = getGrade(percentage);
        float gradePoint = getGradePoint(grade);
        totalGradePoint += gradePoint * courseCredit[i];
    }

    // Calculate CGPA
    return totalGradePoint / totalCredit;
}

// Function to display student result
void displayStudentResult(struct Student student) {
    printf("\n----- Student Result -----\n");
    printf("Student Name: %s\n", student.name);
    printf("Roll: %d\n", student.roll);
    printf("Semester: %s\n", student.semester);
    printf("Registration No: %s\n", student.registrationNo);
    printf("Total CGPA: %.2f\n", student.cgpa);
    printf("CGPA Grade: %c\n", student.cgpaGrade);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        // Display options
        printf("\nOptions:\n");
        printf("1. Create Result\n");
        printf("2. Display All Student Results\n");
        printf("3. Display Specific Student Result\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Create Result
                if (numStudents < MAX_STUDENTS) {
                    struct Student newStudent;

                    // Input student details
                    printf("\nEnter Student Name: ");
                    scanf("%s", newStudent.name);

                    printf("Enter Roll: ");
                    scanf("%d", &newStudent.roll);

                    printf("Enter Semester: ");
                    scanf("%s", newStudent.semester);

                    printf("Enter Registration No: ");
                    scanf("%s", newStudent.registrationNo);

                    printf("Enter Number of Courses: ");
                    scanf("%d", &newStudent.numCourses);

                    // Input course details
                    for (int i = 0; i < newStudent.numCourses; i++) {
                        printf("\nCourse %d\n", i + 1);
                        printf("Enter Course Code: ");
                        scanf("%s", newStudent.courseCode[i]);

                        printf("Enter Course Name: ");
                        scanf("%s", newStudent.courseName[i]);

                        printf("Enter Course Credit: ");
                        scanf("%d", &newStudent.courseCredit[i]);

                        printf("Enter Course Mark: ");
                        scanf("%f", &newStudent.courseMark[i]);
                    }

                    // Calculate CGPA
                    newStudent.cgpa = calculateCGPA(newStudent.numCourses, newStudent.courseCredit, newStudent.courseMark);

                    // Convert CGPA to Grade
                    newStudent.cgpaGrade = getCGPAGrade(newStudent.cgpa);

                    // Add student to the array
                    students[numStudents] = newStudent;
                    numStudents++;

                    printf("\nResult Created Successfully!\n");
                } else {
                    printf("\nMaximum number of students reached!\n");
                }
                break;

            case 2: // Display All Student Results
                if (numStudents == 0) {
                    printf("\nNo student results found!\n");
                } else {
                    printf("\n----- All Student Results -----\n");
                    for (int i = 0; i < numStudents; i++) {
                        displayStudentResult(students[i]);
                    }
                }
                break;

            case 3: // Display Specific Student Result
                if (numStudents == 0) {
                    printf("\nNo student results found!\n");
                } else {
                    int roll;
                    printf("\nEnter Roll Number: ");
                    scanf("%d", &roll);
                    int found = 0;
                    for (int i = 0; i < numStudents; i++) {
                        if (students[i].roll == roll) {
                            displayStudentResult(students[i]);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("\nStudent with Roll Number %d not found!\n", roll);
                    }
                }
                break;

            case 0: // Exit
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 10
#define MAX_NAME_LENGTH 100
#define MAX_CODE_LENGTH 10
#define MAX_GRADES 50

struct Course
{
    char code[MAX_CODE_LENGTH];
    char name[MAX_NAME_LENGTH];
    float credit;
    float mark;
};

struct Student
{
    char name[MAX_NAME_LENGTH];
    char roll[MAX_NAME_LENGTH];
    char semester[MAX_NAME_LENGTH];
    char registrationNo[MAX_NAME_LENGTH];
    int numCourses;
    struct Course courses[MAX_COURSES];
    float cgpa;
    char cgpaGrade;
};

float calculateCGPA(struct Student student)
{
    float totalCredits = 0.0;
    float totalGradePoints = 0.0;
    int hasFailingGrade = 0;

    for (int i = 0; i < student.numCourses; ++i)
    {
        struct Course course = student.courses[i];
        float gradePoint = 0.0;


        if (course.mark < 40)
        {
            hasFailingGrade = 1;
        }
        else
        {
            if (course.mark >= 80)
                gradePoint = 4.00;
            else if (course.mark >= 75)
                gradePoint = 3.75;
            else if (course.mark >= 70)
                gradePoint = 3.50;
            else if (course.mark >= 65)
                gradePoint = 3.25;
            else if (course.mark >= 60)
                gradePoint = 3.00;
            else if (course.mark >= 55)
                gradePoint = 2.75;
            else if (course.mark >= 50)
                gradePoint = 2.50;
            else if (course.mark >= 45)
                gradePoint = 2.25;
            else if (course.mark >= 40)
                gradePoint = 2.00;

            totalGradePoints += gradePoint * course.credit;
            totalCredits += course.credit;
        }
    }

    if (hasFailingGrade)
    {
        return 0.0;
    }

    // Calculate and return CGPA
    return totalCredits == 0 ? 0.0 : totalGradePoints / totalCredits;
}

char* calculateGrade(float cgpa)
{
    if (cgpa >= 4.00)
        return "A+";
    else if (cgpa >= 3.75)
        return "A";
    else if (cgpa >= 3.50)
        return "A-";
    else if (cgpa >= 3.25)
        return "B+";
    else if (cgpa >= 3.00)
        return "B";
    else if (cgpa >= 2.75)
        return "B-";
    else if (cgpa >= 2.50)
        return "C+";
    else if (cgpa >= 2.25)
        return "C";
    else if (cgpa >= 2.00)
        return "D";
    else
        return "F";
}

void createResult(struct Student *student)
{
    printf("Enter Student Name: ");
    fgets(student->name, sizeof(student->name), stdin);
    strtok(student->name, "\n");
    printf("Enter Student Roll: ");
    fgets(student->roll, sizeof(student->roll), stdin);
    strtok(student->roll, "\n");
    printf("Enter Semester: ");
    fgets(student->semester, sizeof(student->semester), stdin);
    strtok(student->semester, "\n");
    printf("Enter Registration No: ");
    fgets(student->registrationNo, sizeof(student->registrationNo), stdin);
    strtok(student->registrationNo, "\n");
    printf("Enter Number of Courses: ");
    scanf("%d", &student->numCourses);
    getchar();

    for (int i = 0; i < student->numCourses; ++i)
    {
        printf("Enter Course Code for Course %d: ", i + 1);
        fgets(student->courses[i].code, sizeof(student->courses[i].code), stdin);
        strtok(student->courses[i].code, "\n");
        printf("Enter Course Name for Course %d: ", i + 1);
        fgets(student->courses[i].name, sizeof(student->courses[i].name), stdin);
        strtok(student->courses[i].name, "\n");
        printf("Enter Course Credit for Course %d: ", i + 1);
        scanf("%f", &student->courses[i].credit);
        printf("Enter Mark for Course %d: ", i + 1);
        scanf("%f", &student->courses[i].mark);
        getchar();
    }

    student->cgpa = calculateCGPA(*student);
    student->cgpaGrade = calculateGrade(student->cgpa);
}

void displayStudentResult(struct Student student) {
    printf("\n------------------------------------------------------\n");
    printf("|                    Student Result                    |\n");
    printf("------------------------------------------------------\n");
    printf("| Name            | Roll       | Semester  | Reg No  |\n");
    printf("------------------------------------------------------\n");
    printf("| %-15s | %-10s | %-9s | %-7s |\n", student.name, student.roll, student.semester, student.registrationNo);
    printf("------------------------------------------------------\n");
    printf("| Total CGPA      | CGPA Grade |           |         |\n");
    printf("------------------------------------------------------\n");
    printf("| %-15.2f |  %-10s |           |         |\n", student.cgpa,  calculateGrade(student.cgpa));
    printf("------------------------------------------------------\n");
}

int main()
{
    int choice;
    struct Student students[MAX_GRADES];
    int numStudents = 0;

    do
    {
        // Display options
        printf("\nOptions:\n");
        printf("1. Create Result\n");
        printf("2. Display All Student Results\n");
        printf("3. Display Specific Student Result\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            getchar();
            if (numStudents < MAX_GRADES)
            {
                createResult(&students[numStudents]);
                numStudents++;
                printf("Result created successfully.\n");
            }
            else
            {
                printf("Maximum number of students reached.\n");
            }
            break;
        case 2:
            if (numStudents == 0)
            {
                printf("No student results to display.\n");
            }
            else
            {
                printf("\n----- All Student Results -----\n");
                for (int i = 0; i < numStudents; ++i)
                {
                    displayStudentResult(students[i]);
                }
            }
            break;
        case 3:
            if (numStudents == 0)
            {
                printf("No student results to display.\n");
            }
            else
            {
                char roll[MAX_NAME_LENGTH];
                printf("Enter Student Roll: ");
                getchar();
                fgets(roll, sizeof(roll), stdin);
                strtok(roll, "\n");
                int found = 0;
                for (int i = 0; i < numStudents; ++i)
                {
                    if (strcmp(students[i].roll, roll) == 0)
                    {
                        displayStudentResult(students[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    printf("Student with Roll %s not found.\n", roll);
                }
            }
            break;
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 0);

    return 0;
}

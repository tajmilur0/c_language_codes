#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 10
#define MAX_NAME_LENGTH 50
#define MAX_CODE_LENGTH 10
#define MAX_GRADES 10

struct Course {
    char code[MAX_CODE_LENGTH];
    char name[MAX_NAME_LENGTH];
    float credit;
    float mark;
};

struct Student {
    char name[MAX_NAME_LENGTH];
    char roll[MAX_NAME_LENGTH];
    char semester[MAX_NAME_LENGTH];
    char regNo[MAX_NAME_LENGTH];
    int numCourses;
    struct Course courses[MAX_COURSES];
};

float calculateCGPA(struct Student student) {
    float totalCredits = 0.0;
    float totalGradePoints = 0.0;
    int hasFailingGrade = 0; // Flag to track if any course has a failing grade

    for (int i = 0; i < student.numCourses; ++i) {
        struct Course course = student.courses[i];
        float gradePoint = 0.0;

        // Check if the course mark is below 40
        if (course.mark < 40) {
            hasFailingGrade = 1; // Set the flag to indicate failing grade
        } else {
            // Calculate grade point based on mark
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

            // Update total grade points and credits
            totalGradePoints += gradePoint * course.credit;
            totalCredits += course.credit;
        }
    }

    // If any course has a failing grade, set CGPA to 0 and grade to "F"
    if (hasFailingGrade) {
        return 0.0;
    }

    // Calculate and return CGPA
    return totalCredits == 0 ? 0.0 : totalGradePoints / totalCredits;
}



char *calculateGrade(float cgpa) {
    if (cgpa >= 4.00)
        return "A+";
    else if (cgpa >= 3.75)
        return "A-";
    else if (cgpa >= 3.50)
        return "A";
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

int main() {
    struct Student student;
    printf("Enter Student Name: ");
    fgets(student.name, sizeof(student.name), stdin);
    strtok(student.name, "\n"); // Remove newline character
    printf("Enter Student Roll: ");
    fgets(student.roll, sizeof(student.roll), stdin);
    strtok(student.roll, "\n"); // Remove newline character
    printf("Enter Semester: ");
    fgets(student.semester, sizeof(student.semester), stdin);
    strtok(student.semester, "\n"); // Remove newline character
    printf("Enter Registration No: ");
    fgets(student.regNo, sizeof(student.regNo), stdin);
    strtok(student.regNo, "\n"); // Remove newline character
    printf("Enter Number of Courses: ");
    scanf("%d", &student.numCourses);
    getchar(); // Clear newline character from input buffer

    for (int i = 0; i < student.numCourses; ++i) {
        printf("Enter Course Code for Course %d: ", i + 1);
        fgets(student.courses[i].code, sizeof(student.courses[i].code), stdin);
        strtok(student.courses[i].code, "\n"); // Remove newline character
        printf("Enter Course Name for Course %d: ", i + 1);
        fgets(student.courses[i].name, sizeof(student.courses[i].name), stdin);
        strtok(student.courses[i].name, "\n"); // Remove newline character
        printf("Enter Course Credit for Course %d: ", i + 1);
        scanf("%f", &student.courses[i].credit);
        printf("Enter Mark for Course %d: ", i + 1);
        scanf("%f", &student.courses[i].mark);
        getchar(); // Clear newline character from input buffer
    }

    float cgpa = calculateCGPA(student);
    char *grade = calculateGrade(cgpa);

    printf("\nCGPA: %.2f\n", cgpa);
    printf("Grade: %s\n", grade);

    return 0;
}

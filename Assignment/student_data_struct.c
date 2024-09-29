#include<stdio.h>

struct{
int roll;
char name[40];
int marks[3];

}student[3];

int main(){


printf("Enter the student details: \n");
for(int i=0;i<3;i++){

    printf("Enter the %d no student roll: ",i+1);
    scanf("%d",&student[i].roll);
    printf("Enter the %d no student name: ",i+1);
    scanf("%s",&student[i].name);
    for(int j=0; j<3;j++){
        printf("Enter the mark no %d : ",j+1);
        scanf("%d",&student[i].marks[j]);
    }
}
for(int i=0;i<3;i++){
    printf("Student No %d details: \n",i+1);
     printf("Student Roll: %d\n",student[i].roll);
    printf("Student name: %s\n",student[i].name);
    for(int j=0;j<3;j++){
            printf("Student marks no %d: %d\n",i+1,student[i].marks[j]);
    }

    printf("\n\n\n\n");

}

return 0;
}

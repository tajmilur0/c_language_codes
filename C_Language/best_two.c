#include<stdio.h>
#include <limits.h>

struct
{
    char name[40];
    int roll;
    int mark[3];

} student[2];

int main()
{
    for(int i=0; i<2; i++)
    {
        printf("Enter the Name: ");
        scanf("%s",&student[i].name);
        printf("Enter the Roll: ");
        scanf("%d",&student[i].roll);
        for(int j=0; j<3; j++)
        {
            printf("Enter  mark of Subject %d : ",j+1);
            scanf("%d",&student[i].mark[j]);
        }
    }

    printf("\n\n\n############=====================================###########");
    printf("\n############=====================================###########");
    printf("\n\n***=====    Name    =====***======  Roll  ====****=====   Average   ==========\n");
    int max1 =  INT_MIN;
    int max2 =  INT_MIN;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(student[i].mark[j]>max1)
            {
                max2=max1;
                max1=student[i].mark[j];
            }
            else
            {
                if(student[i].mark[j] > max2 && student[i].mark[j] < max1)
                {
                    max2=student[i].mark[j];
                }
            }

        }

        //printf("%d and %d\n",max1,max2);
 float average =(max1+max2)/2.00;
    printf("\n\n***=====    %s    =====***======  %d  ====****=====   %.3f   ==========\n",student[i].name,student[i].roll,average);



//printf("The Average of two best mark of:: Name: %s And Roll:: %d : Average %f\n",student[i].name,student[i].roll,average);
        max1 =  INT_MIN;
        max2 =  INT_MIN;
    }

 printf("\n############=====================================###########");

    return 0;
}

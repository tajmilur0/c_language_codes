#include<stdio.h>
struct
{
int roll;
char name[40];
int mark[3];
} s[2];

int main(){
for(int i=0;i<2;i++){
   printf("Enter the Name of the Student:  ");
   scanf("%s",&s[i].name);
   printf("Enter the Roll of the Student:  ");
   scanf("%d",&s[i].roll);
   printf("Enter the number of 3 Subjects:  \n");
   for(int j=0;j<3;j++){
       printf("Enter the marks of Subject number %d :",j+1);
            scanf("%d",&s[i].mark[j]);
   }
}


//Average of best two Marks
    for(int i=0;i<2;i++){
 int max1,max2;
    for(int j=0; j<3; j++)
    {

        if(s[i].mark[j] > max1)
        {

            max2 = max1;
            max1 = s[i].mark[j];
        }
        else if(s[i].mark[j] > max2 && s[i].mark[j] < max1)
        {
            max2 = s[i].mark[j];
        }
    }
    printf("Max: %d min: %d",max1,max2);

    float aveg;
     aveg=(max1+max2)/2.00;

     printf("Average Mark of %s is %f\n",s[i].name,aveg);

    }

}

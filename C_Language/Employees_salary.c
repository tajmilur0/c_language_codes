#include<stdio.h>

struct
{
    int ID;
    char name[40];
    int basic_salary;


} employee[2];
int main()
{

    float HR,TA,MA=2000,PF,Net_Pay;
    printf(":::::::::::::::::::::::::Employee Details:::::::::::::::::::::::\n");
    for(int i=0; i<2; i++)
    {
        printf("Enter the Name: \n");
        scanf("%s",&employee[i].name);
        printf("Enter the ID: \n");
        scanf("%d",&employee[i].ID);
        printf("Enter the Basic Salary: \n");
        scanf("%d",&employee[i].basic_salary);
    }
    for(int i=0; i<2; i++)
    {
        printf("\n::::::::::::::::::::::......Salary Details of  Id: %d..........::::::::::::::::::::::::\n",employee[i].ID);
        if(employee[i].basic_salary<=10000)
        {
            HR=(employee[i].basic_salary/100)*45;
        }
        else if(employee[i].basic_salary>10000 && employee[i].basic_salary<=20000)
        {
            HR=(employee[i].basic_salary/100)*40;
        }
        else if(employee[i].basic_salary>20000)
        {
            HR=(employee[i].basic_salary/100)*35;
        }
        else
        {

        }

        TA = (employee[i].basic_salary/100)*5;
        PF = (employee[i].basic_salary/100)*10;

        float total_salary = employee[i].basic_salary+HR+TA+PF;
        float Net_Pay = total_salary - PF;

        printf("The Total Salary of %s :: %f\n",employee[i].name,total_salary);
               printf("The Total Salary of %s :: %.3f\n",employee[i].name,Net_Pay);
               printf("\n\n\n\n\n");

    }



    return 0;


}

#include<stdio.h>

int main()
{
    int n;
   printf("Enter the Size of array:  ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the numbers:  \n");
    int i;
    for( i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The Numbers: ");
    for(i=0; i<n; i++)
    {
        printf("%d   ",a[i]);
    }

    //Find-out Maximum number

    for(i=0;i<n;i++){
        if(a[0]<a[i])
            a[0]=a[i];
    }
    printf("\nHighest Number is: %d",a[0]);

    return 0;
}

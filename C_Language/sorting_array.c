#include<stdio.h>
int main()
{

    int n, a[100];

    printf("Enter the the number of Values:: \n");

    scanf("%d",&n);
    printf("Enter the values:   \n");
    for(int i=0; i<n; i++)
    {

        scanf("%d",&a[i]);
    }
    printf("The Values Is :: ");
    for(int i=0; i<n; i++)
    {
        printf(" %d", a[i]);

    }

    //sorting
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nThesorting Values Is :: ");
    for(int i=0; i<n; i++)
    {
        printf(" %d", a[i]);

    }



    return 0;
}

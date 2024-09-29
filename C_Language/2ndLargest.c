#include <stdio.h>

int main(){
 int n;

 printf("Enter the array size:  ");

 scanf("%d",&n);
 int i, a[n];

 printf("Enter the numbers:  ");
 for(i=0;i<n;i++){
    scanf("%d",&a[i]);
 }
 printf("The Numbers: \n");
 for(i=0;i<n;i++){
    printf("%d ",a[i]);
 }
 for(i=0;i<n;i++){
        if(a[i]>a[0]){
            a[0]=a[i];
        }


 }

 printf("\nThe second Highest number is: %d",a[0]);

return 0;
}

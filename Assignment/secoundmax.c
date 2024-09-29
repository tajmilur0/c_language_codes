#include<stdio.h>

int main(){
int numE;
printf("Enter the number of element: ");
scanf("%d",&numE);
int arr[100];
    printf("Enter the element: ");
for(int i= 0;i<numE;i++){

    scanf("%d",&arr[i]);
}
//maximum and second maximum

int max= arr[0];
int s_max = arr[0];

for(int i =0;i<numE;i++){
    if(arr[i]>max){
        s_max = max;
        max= arr[i];
    }
    else if(arr[i]>s_max && arr[i] != max){
        s_max = arr[i];
    }
}

printf("Maximum: %d\n",max);
printf("Second Maximum: %d\n",s_max);




return 0;
}

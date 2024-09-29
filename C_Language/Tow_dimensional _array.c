#include<stdio.h>


int main(){

int a[4][4];

printf("Enter the values:: ");

for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        printf("\n a[%d][%d] = ",i,j);
        scanf("%d",&a[i][j]);
    }
}

for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        printf(" %d  ",a[i][j]);
    }
    printf("\n");
}

printf("Addition of Boundary values::: \n");

int sum=0;

for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
       if(i==0 || j==0 || i==4-1 || j==4-1)
        sum = sum+a[i][j];
    }
}

printf("\n The Addition of boundary values is :  %d",sum);




return 0;



}

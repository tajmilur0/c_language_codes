#include<stdio.h>

int main(){

    int arr[]={1,4,2,5,4,8,7};
    int temp;
    for(int i=0;i<7;i++){
       for(int j=i+1;j<7;j++){
        if(arr[i]<arr[j]){
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
       }
    }
    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
return 0;
}

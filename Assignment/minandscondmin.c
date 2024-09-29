#include<stdio.h>
#include<limits.h>
int main(){
int arr[]={2,2};

int min = INT_MAX;
int s_min = INT_MAX;

for(int i=0; i<2;i++){
    if(arr[i]<min){
        s_min = min;
        min=arr[i];
    }
    else if(arr[i]<s_min && arr[i] != min){
        s_min = arr[i];
    }
}
if(s_min==INT_MAX){
    printf("mim=%d\n",min);
    printf("no s_min");
}
else{
      printf("mim=%d\n",min);
    printf("no s_min %d",s_min);
}

return 0;
}

#include<stdio.h>

void bublesort(int arr[],int n){
 for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j]= arr[j+1];
            arr[j+1] = temp;
        }
    }
 }

}

int binarySearch(int arr[],int left, int right, int target){

while(left<=right){
    int mid = left + (right-left)/2;
    if(arr[mid] == target)
        return mid;
        if(arr[mid]<target)
            left = mid+1;
        else
            right = mid-1;
}


return -1;
}

int main(){
int arr[] = {34,35,36,37,38,39,40};
int n = sizeof(arr)/sizeof(arr[0]);
bublesort(arr,n);
int target = 38;
int result = binarySearch(arr,0,n-1,target);
if(result == -1){
    printf("Not Found");
}
else{
    printf("Element is found at %d position",result+1);
}
}

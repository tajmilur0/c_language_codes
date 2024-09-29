#include<stdio.h>

int main(){

int num[] ={12,45,13,14,50};
int value = 46;
int position=-1;

for(int i=0;i<5;i++){

    if(value==num[i]){
        position=1+i;
        break;
    }
}
if(position == -1)
    printf("Data Not Found");
else
    printf("The position of %d is: %d",value,position);


return 0;
}

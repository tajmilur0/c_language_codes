#include<stdio.h>

int main(){
int num[] = {11,23,43,53,12,77};
int value;
int pos = -1;
 printf("Enter the value you want to search....\n");
 scanf("%d",&value);
 for(int i=0;i<6;i++){
    if(value == num[i]){
        pos = i+1;
        break;
    }
 }
 if(pos == -1){
    printf("Not Found\n");
 }
 else {
    printf("The value %d found at %d posiion",value,pos);
 }

return 0;
}

#include<stdio.h>

int main(){

int a[]={11,12,13,14,15,16};
int *ptr;
ptr= &a[0];
for(int i =0; i<6;i++){
    printf("%d\n",*ptr);
    ptr++;
}

return 0;
}

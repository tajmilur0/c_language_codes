#include<stdio.h>

int main(){
 int x=12;
 int *p;

 p=&x;

 printf("The value of x is : %d\n",x);
 printf("The memory Address of x is : %d\n",&x);

 printf("The value of p is : %d\n",p);
 printf("The value of *p is : %d\n",*p);
  printf("The address of *p is : %d",&*p);

return 0;
}

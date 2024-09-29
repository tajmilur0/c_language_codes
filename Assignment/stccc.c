#include<stdio.h>

#define CAPACITY 4

int arr[CAPACITY];
int top = -1;

void push(int x){

if(top<CAPACITY-1){
    top = top+1;
    arr[top] = x;
}
else{
    printf("Overflow\n");
}

}

int pop(){
if(top>=0){
        int val = arr[top];
    top = top-1;
return val;
}
else{
    printf("Stack in empty\n");
}


}

int peek(){
if(top>=0){
    return arr[top];
}
else{
    printf("Stack is empty\n");
}

}
int main(){
push(10);
push(11);
push(12);
push(13);
printf("The top item is %d\n",peek());
printf("The pop item is %d\n",pop());
printf("The top item is %d\n",peek());
push(17);
printf("The top item is %d\n",peek());







}

#include<stdio.h>
#define CAPACITY 5

int stack[CAPACITY];
int top = -1;

void push(int x){
if(top<CAPACITY-1){
    top = top+1;
    stack[top] = x;
}
else{
    printf("Overflow.........\n");
}
}
int pop(){
if(top>=0){
        int val = stack[top];
        top = top-1;
        return val;
}
else{
    printf("Stack is emty\n");
}
}

int peak(){
if(top>=0){
    return stack[top];
}
else{
    printf("Stack is emty\n");
}
}

int main(){
peak();
push(10);
push(11);
push(12);
push(13);
printf("The pop item is %d\n",pop());
printf("The top item is %d",peak());
}

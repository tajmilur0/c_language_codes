#include <stdio.h>

#define CAPACITY 3
int stack[CAPACITY];
int top = -1;

void push(int x){
    if(top < CAPACITY - 1){
        top = top+1;
        stack[top] = x;

    }
    else{
        printf("Overflow.......");
    }
}

int pop(){
if(top>=0){
    int val = stack[top];
    top = top-1;
    return val;
}
else{
    printf("The stack is empty\n");
}

}
int peek(){

if(top>=0){
    return stack[top];
}
else{
    printf("Stack is empty\n");
}

}

int main(){
printf("Stack Impletation..............\n");
push(10);
push(11);
push(12);
push(13);
printf("All value of the stack....\n");

for(int i=0;i<top+1;i++){
    printf("%d\n",stack[i]);
}
printf("pop item is %d\n",pop());
printf("the top item is %d",peek());
printf("All value of the stack....\n");
for(int i=0;i<top+1;i++){
    printf("%d\n",stack[i]);
}
printf("pop item is %d\n",pop());
printf("the top item is %d",peek());
printf("All value of the stack....\n");
for(int i=0;i<top+1;i++){
    printf("%d\n",stack[i]);
}
}

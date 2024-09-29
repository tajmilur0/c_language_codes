#include<stdio.h>

#define CAPACITY 5
int front = -1, rear = -1;
int queue[CAPACITY];
void enqueue(int x)
{
    if(rear == CAPACITY-1){
        printf("Queue is full\n");
    }
    else{
       if(front == -1){
        front = 0;
       }
       rear++;
       queue[rear] = x;
    }
}

void dequeue(){
if(front == -1 || front>rear){
    printf("Queue is emty \n");
}
else{
    printf("Dequeueing element: %d\n",queue[front]);
    front++;
}
}

void disply(){
if(front == -1 || front>rear){
    printf("queue is emty\n");
}
else{
    printf("queue element: \n");
    for(int i=front; i<=rear; i++){
        printf("%d",queue[i]);
    }
    printf("\n");
}
}

int main(){

enqueue(10);
enqueue(11);
enqueue(12);
enqueue(13);
enqueue(14);
enqueue(15);
disply();
dequeue();
disply();
dequeue();
disply();


return 0;
}

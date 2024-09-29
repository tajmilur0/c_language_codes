#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
void enqueue();
  void dequeue();
  void show();
int queue[SIZE];
int front = -1;
int rear = -1;



int main(){

int ch;

while(1){

    printf("1. Enqueue operation\n");
    printf("2. Dequeue operation\n");
    printf("3. Display operation\n");
    printf("4. Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);

    switch(ch){
case 1:
    enqueue();
    break;
case 2:
    dequeue();
    break;
case 3:
    show();
    break;
case 4:
    exit(0);
    break;
default:
    printf("Incorrect choice\n");

    }




}
return 0;
}

void enqueue(){
int item;

if(rear == SIZE-1){
    printf("OverFlow\n");
}
else{
    if(front == -1 )
        front =0;
    printf("Enter the element to insert: ");
    scanf("%d",&item);
    rear = rear+1;
    queue[rear] = item;
}


}

void dequeue(){
if(front == -1 || front > rear){
    printf("Underflow\n");
    return;
}
else{
    printf("deleted item %d \n",queue[front]);
    front = front + 1;
}

}

void show(){
if(front == -1){
    printf("Queue is empty\n");
}
else{
    printf("Queue------------\n");
    for(int i = front; i<=rear; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

}


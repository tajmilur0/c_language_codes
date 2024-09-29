#include <stdio.h>

#define SIZE 100

void enqueue();
void dequeue();
void show();
int arr[SIZE];
int front = -1;
int rear = -1;

int main(){

int ch;
while(1){

    printf("1. Enqueue operation\n");
    printf("2. Dequeue operation\n");
    printf("3. Display operation\n");
    printf("4. Exit\n");
    printf("Enter your choice for operation: \n");
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
        case 4:
        exit(0);
        default:
            printf("Incorrect choice\n");

    }
}

void enqueue(){
int item;
if(rear == SIZE - 1)
printf("Overflow\n");

else{
    if(front == -1)
        front =0;
    printf("Enter the element to be insert: ");
    scanf("%d",&item);
    rear = rear+1;
    arr[rear] = item;
}
}

void dequeue(){
if(front == -1 || front > rear){
    printf("Uderflow\n");
    return;
}
else{
    printf("Element deleted from the queue: %d",arr[front]);
    front = front + 1;
}

}

void show(){
if(front == -1)
    printf("Empty Queue:\n");
else{
    printf("Queue: \n");
    for(int i=0;i<=rear;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
}

}

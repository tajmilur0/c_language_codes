
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void enqueue();
void dequeue();
void show();
int arr[SIZE];
int front = -1;
int rear = -1;

int main() {
    int ch;
    while (1) {
        printf("1. Enqueue operation\n");
        printf("2. Dequeue operation\n");
        printf("3. Display operation\n"); // Corrected option number
        printf("4. Exit\n"); // Corrected option number
        printf("Enter your choice for operation: \n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break; // Added break statement
            case 4:
                exit(0);
            default:
                printf("Incorrect choice\n");
        }
    }
    return 0;
}

void enqueue() {
    int item;
    if (rear == SIZE - 1)
        printf("Overflow\n");
    else {
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        rear = rear + 1;
        arr[rear] = item;
        if (front == -1)
            front = 0;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
        return;
    } else {
        printf("Element deleted from the queue: %d\n", arr[front]);
        front = front + 1;
        if (front > rear) // Resetting front and rear if queue becomes empty
            front = rear = -1;
    }
}

void show() {
    if (front == -1)
        printf("Empty Queue\n");
    else {
        printf("Queue: \n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

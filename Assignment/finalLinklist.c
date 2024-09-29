#include <stdio.h>
#include <stdlib.h>

typedef struct MyNode{
int data;
struct MyNode *next;
}Node;

void insert(Node *s, int data){
    while(s->next != NULL){
        s=s->next;
    }
    s->next = (Node*)malloc(sizeof(Node));
    s->next->data = data;
    s->next->next = NULL;
}

void disply(Node *s){
while(s->next != NULL){
    printf("%d\n",s->next->data);
    s=s->next;
}
}

void search(Node *s, int data){
    int count;
while(s->next != NULL){
    if(s->next->data == data){
        count++;
    }
    s=s->next;
}
printf("Total %d result found: ",count);
}

void deleteNode(Node *s, int data){
while(s->next != NULL){
    if(s->next->data == data){
        s->next =s->next->next;
        return 0;
    }
    s=s->next;
}
}

int main(){
    int sch,del,numE,Elm;

    Node *first = (Node*)malloc(sizeof(Node));
    first->next = NULL;

    printf("Enter the number of element to insert: ");
    scanf("%d",&numE);
    for(int i= 0;i<numE; i++){
        printf("The element no %d : ",i+1);
        scanf("%d",&Elm);
        insert(first,Elm);
    }

    printf("Displying all the element: \n");
    disply(first);
    printf("Enter the searching item: ");
    scanf("%d",&sch);
    search(first,sch);
    printf("Enter the deleting item: ");
    scanf("%d",&del);
    deleteNode(first,del);
    disply(first);
}


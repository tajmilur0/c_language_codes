#include<stdio.h>
#include<stdlib.h>

typedef struct MyNode{

int data;
struct MyNode *next;
}Node;

void insert(Node *s, int data){

while(s->next != NULL){
    s = s->next;
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

void searchNode(Node *s, int data){
    int count;
while(s->next != NULL){
    if(s->next->data == data){
        count++;
    }
     s= s->next;
}
 printf("Total %d result found \n",count);
}

void DeleteNode(Node *s, int data){
while(s->next != NULL){
    if(s->next->data == data){
        s->next = s->next->next;
        return 0;
        }
        s = s->next;
}

}
int main(){
int del,numE,elem,sch;

Node *first = (Node*)malloc(sizeof(Node));
first->next = NULL;

printf("Enter the number of element to insert: ");
scanf("%d",&numE);
printf("Enter the elements: \n");
for(int i=0;i<numE;i++){
    printf("Enter %d no element: ",i+1);
    scanf("%d",&elem);
    insert(first,elem);
}
printf("Disply the Link List.........\n");
disply(first);
printf("Enter the searching element: ");
scanf("%d",&sch);
searchNode(first,sch);
printf("Enter the delete element: ");
scanf("%d",&del);
DeleteNode(first,del);
printf("Disply the link list..............\n");
disply(first);

}

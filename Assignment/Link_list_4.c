#include<stdio.h>
#include<stdlib.h>

typedef struct MyNode{

int data;
struct MyNode *next;
}node;

void insert(node *s,int data){

while(s->next != NULL){
    s=s->next;
}
s->next= (node*)malloc(sizeof(node));
s->next->data=data;
s->next->next=NULL;

}

void disply(node *s){
while(s->next != NULL){
    printf("%d\n",s->next->data);
    s=s->next;
}
}

void search(node *s,int data){
    int count;
while(s->next != NULL){
    if(s->next->data==data)
    {
    count++;
    }
    s=s->next;
}
printf("Total %d results found",count);

}
 void deleteNode(node *s,int data){
 while(s->next != NULL){
    if(s->next->data == data){
        s->next=s->next->next;
        return 0;
    }
    s=s->next;
 }

 }

 int main(){
 int numE,elem,sch,del;
 node *first = (node*)malloc(sizeof(node));
 first->next = NULL;

 printf("Enter the number of elements: ");
 scanf("%d",&numE);
 for(int i=0;i<numE;i++){
    printf("Enter the %d no element: ",i+1);
    scanf("%d",&elem);
    insert(first,elem);
 }

 disply(first);

 printf("Enter the searching Elements: ");
 scanf("%d",&sch);
 search(first,sch);
 printf("\nEnter the delete item : ");
 scanf("%d",&del);
 deleteNode(first,del);
 disply(first);



 }

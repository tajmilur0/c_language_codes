#include<stdio.h>
#include<stdlib.h>

typedef struct myNode{

int data;
struct myNode *next;
}node;

void insert(node *s,int data){
while(s->next != NULL){
    s=s->next;
}
s->next= (node*)malloc(sizeof(node));
s->next->data= data;
s->next->next=NULL;
}

void display(node *s){

while(s->next!=NULL){
    printf("%d\n",s->next->data);
    s=s->next;
}
}
void search(node *s,int data){
    int count;
while(s->next!=NULL){

    if(s->next->data == data){
        count++;
    }
    s=s->next;
}
        printf("Total %d results found");
}

void deleteNode(node *s,int data){
while(s->next!=NULL){

    if(s->next->data== data){
        s->next= s->next->next;
        return 0;
    }
    s=s->next;
}
}

int main(){
int NumElements,element,sch,del;
node *first = (node*)malloc(sizeof(node));

first->next = NULL;
printf("Enter the number of Elements\n");
scanf("%d",&NumElements);
for(int i=0;i<NumElements;i++){
    printf("Enter element no %d\n",i+1);
    scanf("%d",&element);
    insert(first,element);
}
display(first);
printf("Enter the searching elements: ");
scanf("%d",&sch);
search(first,sch);
printf("\nEnter the deleted item: ");
scanf("%d",&del);
deleteNode(first,del);
display(first);



}

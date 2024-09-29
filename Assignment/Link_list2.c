#include<stdio.h>

#include<stdlib.h>

typedef struct MyNode{

int data;
struct MyNode *next;
}Node;


void insert(Node *s,int data){

while(s->next != NULL)
{
    s=s->next;
}
s->next = (Node*)malloc(sizeof(Node));
s->next->data= data;
s->next->next = NULL;

}

void disply(Node *s){
while(s->next != NULL)
{
    printf("%d\n",s->next->data);
    s=s->next;
}
}

void search(Node *s,int data){

int count = 0;
while(s->next!=NULL)
{
    if(s->next->data==data){
        count++;
    }
    s=s->next;
}
printf("Total %d results found\n",count);

}

void deleteNode(Node *s,int data){

while(s->next!=NULL){
    if(s->next->data==data){
        s->next = s->next->next;
        return 0;
    }
    s=s->next;
}
}

void main(){
    int sch,del;
Node *first = (Node*) malloc(sizeof(Node));
first->next= NULL;
 int numElements, element;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        insert(first, element);
    }
disply(first);
printf("\n Enter the searching item: ");
scanf("%d",&sch);

search(first,sch);
printf("\n Enter the deleting item: ");
scanf("%d",&del);
deleteNode(first,del);
disply(first);

}


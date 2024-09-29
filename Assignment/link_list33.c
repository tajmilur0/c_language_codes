#include<stdio.h>

typedef struct myNode{


int data;
struct myNode *next;

}node;

void insert(node *s, int data){

while(s->next != NULL){

    s=s->next;
}
s->next = (node*)malloc(sizeof(node));
s->next->data = data;
s->next->next=NULL;

}

void disply(node *s){
while(s->next != NULL){
    printf("%d\n",s->next->data);
    s=s->next;

}

}

void search(node *s, int data){
    int count;
while(s->next != NULL){

    if(s->next->data == data){
        count++;
    }
    s=s->next;

}

printf("Total %d result found",count);
}

void deleteNOde(node *s, int data){

while(s->next != NULL){

    if(s->next->data == data){
        s->next = s->next->next;
    }
    s= s->next;
}
}

int main(){

int numE,elem,sch,del;
 node *first = (node*)malloc(sizeof(node));
 first->next =NULL;

 printf("Enter the number of elements: ");
 scanf("%d",&numE);
 for(int i=0;i<numE;i++){
    printf("Enter the element no %d: ",1+i);
    scanf("%d",&elem);
    insert(first,elem);
 }
 disply(first);
 printf("Enter the searching item: ");
 scanf("%d",&sch);
 search(first,sch);
 printf("\nEnter the deleted item: ");
 scanf("%d",&del);
 deleteNOde(first,del);
 disply(first);


}


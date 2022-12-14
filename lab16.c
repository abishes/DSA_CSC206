//WAP to implement the operation on circular linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}nodeType;
nodeType *first= NULL, *last= NULL;
void enqueue(int data);
void dequeue();
void traverse();

int main(){
    for(int i=0; i<5; i++){
        enqueue(i);
        traverse();
    }
    for(int i=0; i<=5; i++){
        dequeue();
        traverse();
    }
}

void enqueue(int data){
    nodeType *newNode= (nodeType*)malloc(sizeof(nodeType));
    newNode->data=data;
    printf("%d enqueued\n", data);
    if(first== NULL){
        first= last =newNode;
        first->next = last->next = newNode;
        return;
    }
    newNode->next = first;
    first=newNode;
    last->next = first;

}

void dequeue(){
    if(first == NULL){
        printf("list is empty\n");
        return;
    }
    printf("%d dequeued\n", last->data);
    if(first->next == first){
        free(first);
        first = last = NULL;
        return;
    }
    nodeType *temp=first;
    while(temp->next != last)
        temp= temp->next;
    free(temp->next);
    last=temp;
    last->next=first;
}
void traverse(){
    nodeType *temp= first;
    while(temp != last){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",last->data);
}
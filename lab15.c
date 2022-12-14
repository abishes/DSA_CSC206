//WAP to implement the operation on circular linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}nodeType;
nodeType *first= NULL, *last= NULL;
void push(int data);
void pop();
void traverse();

int main(){
    for(int i=0; i< 5; i++){
        push(i);
        traverse();
    }
    for(int i=0;i<=5;i++){
        pop();
        traverse();
    }
}

void push(int data){
    nodeType *newNode= (nodeType*)malloc(sizeof(nodeType));
    newNode->data=data;
    printf("%d pushed\n", data);
    if(first== NULL){
        first= last =newNode;
        first->next = last->next = newNode;
        return;
    }
    newNode->next = first;
    first=newNode;
    last->next = first;

}
void pop(){
    if(first == NULL){
        printf("list is empty\n");
        return;
    }
    printf("%d poped\n", first->data);
    if(first->next == first){
        free(first);
        first = last = NULL;
        return;
    }
    nodeType *temp= first;
    first=first->next;
    last->next=first;
    free(temp);
}
void traverse(){
    nodeType *temp= first;
    while(temp != last){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",last->data);
}
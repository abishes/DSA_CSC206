//WAP to implement stack using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}nodeType;
nodeType *rear = NULL;
void enqueue(int data){
    nodeType *newNode = (nodeType*)malloc(sizeof(nodeType));
    newNode->data = data;
    printf("%d enqueued\n", data);
    if(rear == NULL){
        rear = newNode;
        rear->next=NULL;
        return;
    }
    newNode->next = rear;
    rear = newNode;
}
void dequeue(){
    if(rear == NULL){
        printf("Queue is empty\n");
        return;
    }
    if(rear->next == NULL){
        printf("%d dequeued", rear->data);
        free(rear);
        rear = NULL;
        return;
    }
    nodeType *temp= rear;
    while(temp->next->next != NULL)
        temp = temp->next;
    printf("%d dequeued\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}
void traverse(){
    nodeType *temp = rear;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    for(int i =10; i<15; i++){
        enqueue(i);
        traverse();
    }
    for (int i = 0; i <= 5; i++){
        dequeue();
        traverse();
    }
    
}
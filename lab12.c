//WAP to implement stack using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}nodeType;
nodeType *top = NULL;
void push(int data){
    nodeType *newNode = (nodeType*)malloc(sizeof(nodeType));
    newNode->data = data;
    printf("%d pushed\n", data);
    if(top == NULL){
        top = newNode;
        top->next= NULL;
        return;
    }
    newNode->next = top;
    top = newNode;
}
void pop(){
    if(top == NULL){
        printf("queue is empty\n");
        return;
    }
    printf("%d poped\n", top->data);
    if(top->next == NULL){
        free(top);
        top = NULL;
        return;
    }
    nodeType *temp= top;
    top=top->next;
    free(temp);
}
void traverse(){
    nodeType *temp = top;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    for(int i =10; i<15; i++){
        push(i);
        traverse();
    }
    for (int i = 0; i <= 5; i++){
        pop();
        traverse();
    }
    
}
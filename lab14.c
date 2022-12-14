//WAP to implement the operation on circular linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}nodeType;
nodeType *first= NULL, *last= NULL;
void insertAtBeg(int data);
void insertAtEnd(int data);
void deleteAtBeg();
void deleteAtEnd();
void traverse();

int main(){
    insertAtBeg(10);
    traverse();
    insertAtBeg(20);
    traverse();
    insertAtEnd(30);
    traverse();
    insertAtEnd(40);
    traverse();
    deleteAtBeg();
    traverse();
    deleteAtEnd();
    traverse();
}

void insertAtBeg(int data){
    nodeType *newNode= (nodeType*)malloc(sizeof(nodeType));
    newNode->data=data;
    printf("inserted at front\n");
    if(first== NULL){
        first= last =newNode;
        first->next = last->next = newNode;
        return;
    }
    newNode->next = first;
    first=newNode;
    last->next = first;

}
void insertAtEnd(int data){
    nodeType *newNode= (nodeType*)malloc(sizeof(nodeType));
    newNode->data=data;
    printf("inserted at end\n");
    if(first== NULL){
        first= last =newNode;
        first->next = last->next = newNode;
        return;
    }
    last->next=newNode;
    last=newNode;
    last->next= first;
}
void deleteAtBeg(){
    if(first == NULL){
        printf("list is empty\n");
        return;
    }
    printf("deleted 1st item\n");
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
void deleteAtEnd(){
    if(first == NULL){
        printf("list is empty\n");
        return;
    }
    printf("deleted last item\n");
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
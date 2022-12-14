//WAP to implement the operation on double linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}nodeType;
nodeType *head = NULL;

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
    if(head== NULL){
        head =newNode;
        head->next = head->prev = newNode;
        return;
    }
    head->prev= newNode;
    newNode->next = head;
    newNode->prev =NULL;
    head = newNode;

}
void insertAtEnd(int data){
    nodeType *newNode= (nodeType*)malloc(sizeof(nodeType));
    newNode->data=data;
    printf("inserted at end\n");
    if(head== NULL){
        head=newNode;
        head->next = head->prev = newNode;
        return;
    }
    newNode->prev= head->prev;
    newNode->next=head;
    head->prev=newNode;
}
void deleteAtBeg(){
    if(head == NULL){
        printf("list is empty\n");
        return;
    }
    printf("deleted 1st item\n");
    if(head->next == NULL){
        free(head);
        head->prev= NULL;
        return;
    }
    nodeType *temp= head;
    head = head->next;
    head->prev= NULL;
    free(temp);
}
void deleteAtEnd(){
    if(head == NULL){
        printf("list is empty\n");
        return;
    }
    printf("deleted last item\n");
    if(head->next == NULL){
        free(head);
        head->prev= NULL;
        return;
    }
    nodeType *temp=head;
    while(temp->next->next != NULL)
        temp= temp->next;
    free(temp->next);
    temp->next = NULL;

}
void traverse(){
    nodeType *temp= head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
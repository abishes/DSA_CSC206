//WAP to implement the operation on linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}nodeType;
nodeType *head= NULL;

nodeType* createNode(int newData);
void insertAtBeg();
void insertAtEnd();
void insertAtPos();
void deleteAtBeg();
void deleteAtEnd();
void deleteAtPos();
void traverse();

int main(){
    int choice;
    printf(
            "1->insert at the beginning\n"
            "2->insert at the end\n"
            "3->insert at required position\n"
            "4->delete first\n"
            "5->delete last\n"
            "6->delete at required position\n"
            "7->traverse at required position\n"
            "8->exit\n");
    do{
        printf("Choose: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtBeg();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPos();
            break;
        case 4:
            deleteAtBeg();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtPos();
            break;
        
        case 7:
            traverse();
            break;
        case 8:
            return 0;
        default:
            break;
        }
    }while(1);
}

void insertAtBeg(){
    int data;
    printf("Enter data to be inserted at the beginning: ");
    scanf("%d", &data);
    if(head == NULL){
        head = createNode(data);
        return;
    }
    nodeType *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(){
    int data;
    printf("Enter data to be inserted at the end: ");
    scanf("%d", &data);
    if(head== NULL){
        head = createNode(data);
        return;
    }
    nodeType *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next= createNode(data);
}
void insertAtPos(){
    int data, pos;
    printf("Enter position and data: ");
    scanf("%d %d", &pos, &data);
    nodeType *newNode = createNode(data);
    nodeType *temp = head;
    for(int i=1; i < pos - 1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

nodeType* createNode(int newData){
    nodeType *newNode= (nodeType*)malloc(sizeof(nodeType));
    newNode->data= newData;
    newNode->next=NULL;
    return newNode;
}
void deleteAtBeg(){
    if(head == NULL){
        printf("list is empty\n");
        return;
    }
    printf("deleted 1st item\n");
    if(head->next == NULL){
        free(head);
        head->next = NULL;
        return;
    }
    nodeType *temp= head;
    head=head->next;
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
        head->next = NULL;
        return;
    }
    nodeType *temp= head;
    while(temp != NULL){
        temp = temp->next;
    }
    free(temp);
}
void deleteAtPos(){
    if(head == NULL){
        printf("list is empty\n");
        return;
    }
    nodeType *tempHead = head, *temp;

    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    for(int i=1; i<pos-1; i++){
        tempHead= tempHead->next;
    }
    temp = tempHead->next;
    tempHead->next= temp->next;
    free(temp);

}
void traverse(){
    nodeType *temp= head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// WAP to implement stack using array
#include<stdio.h>
#define max 5
typedef struct{
    int info[max];
    int top;
} stack;
void creatEmptyStack(stack* st){
    st->top=-1;
}
int isFull(stack* st){
    return st->top == max - 1;
}
int isEmpty(stack* st){
    return st->top == -1;
}
void push(stack* st, int data){
    if(isFull(st)){
        printf("Stack is full\n");
        return;
    }
    printf("%d pushed\n", data);
    st->info[++st->top]= data;
}
void pop(stack* st){
    if(isEmpty(st)){
        printf("Stack is empty\n");
        return;
    }
    printf("%d poped\n", st->info[st->top--]);
}
int main(){
    int i;
    stack st;
    creatEmptyStack(&st);
    for(i=0; i<= max; i++){
        push(&st, i);
    }
    for(i=0; i<= max; i++){
        pop(&st);
    }
    return 0;
}
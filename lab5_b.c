//WAP to to convert infix to postfix expression
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 30
typedef struct{
    char info[max];
    int top;
} stack;
void push(stack* st, char data);
char pop(stack* st);
int precedence(char x);
int main(){
    char infix[]= "(A+B*C$D)/((E+F-G)*H)$I/J";
    int i;
    printf("The infix expression is: %s\n", infix);
    stack postStack, opStack;
    postStack.top= -1;
    opStack.top = -1;
    for(i=0; i< strlen(infix); i++){
        if(infix[i]== '('){
            push(&opStack, infix[i]);
        }
        else if(isalpha(infix[i])){
            push(&postStack, infix[i]);
        }
        else if( infix[i]== ')'){
            while(opStack.info[opStack.top] != '('){
                push(&postStack, pop(&opStack));
            }
            pop(&opStack);
        }
        else{
            while(precedence(opStack.info[opStack.top])> precedence(infix[i])){
                push(&postStack, pop(&opStack));
            }
            push(&opStack, infix[i]);
        }
    }
    while(opStack.top != -1){
        push(&postStack, pop(&opStack));
    }
    push(&postStack, '\0'); // for ending string
    printf("The postfix expression is: %s\n", postStack.info);
}

void push(stack* st, char data){
    if(st->top== max - 1){
        printf("Stack is full\n");
        return;
    }
    st->info[++st->top]= data;
}
char pop(stack* st){
    if(st->top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    char poped = st->info[st->top--];
    return  poped;
}

int precedence(char x){
    switch (x)
    {
    case '$': return 4;
    case '/':
    case '*': return 3;
    case '+':
    case '-': return 2;    
    default: return 1;
    }
}
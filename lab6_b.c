// WAP to evaluate postfix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define max 5
typedef struct{
    int info[max];
    int top;
} stack;
void push(stack* st, int data);
int pop(stack* st);
int realvalue(char ch);
int main(){
    char postExpression[] = "+A-/B$CD*E+F-/GHI";
    printf("postfix expression is %s\n", postExpression);
    strrev(postExpression);
    int i, op1, op2;
    stack vstack;
    vstack.top=-1;
    for(i=0;i<strlen(postExpression); i++){
        if( isalpha(postExpression[i])){
            push(&vstack, realvalue(postExpression[i]));
        }
        else{
            op1 = pop(&vstack);
            op2 = pop(&vstack);
            switch (postExpression[i])
            {
            case '+':
                push(&vstack, op1 + op2);
                break;
            case '-':
                push(&vstack, op1 - op2);
                break;
            case '/':
                push(&vstack, op1 / op2);
                break;
            case '*':
                push(&vstack, op1 * op2);
                break;
            case '$':
                push(&vstack, pow(op1, op2));
                break;
            default:
                break;
            }
        }
    }
    printf("The result is %d\n", pop(&vstack));
}
void push(stack* st, int data){
    if(st->top==max -1){
        printf("Stack is full\n");
        return;
    }
    st->info[++st->top]= data;
}
int pop(stack* st){
    if(st->top == -1){
        printf("Stack is empty\n");
        exit(0);
    }
    int poped =st->info[st->top--];
    return poped;
}
int realvalue(char ch){
    switch (ch)
    {
    case 'A': return 1;
    case 'B': return 2;
    case 'C': return 3;
    case 'D': return 2;
    case 'E': return 1;
    case 'F': return 5;
    case 'G': return 9;
    case 'H': return 3;
    case 'I': return 2;
    default : return 0;
    }
}
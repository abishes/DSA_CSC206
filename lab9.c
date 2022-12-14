//WAP to implement array implemented circular queue
#include<stdio.h>
#define max 5
typedef struct {
    int info[max];
    int front;
    int rear;
} cqueue;
void enqueue(cqueue *q, int data);
void dequeue(cqueue *q);
void traverse(cqueue *q);
int main(){
    int i;
    cqueue q;
    q.front = q.rear = max - 1;
    for(i=0; i<= max; i++){
        enqueue(&q, i);
        traverse(&q);
    }
    for(i=0; i<= max; i++){
        dequeue(&q);
       traverse(&q);
    }
    enqueue(&q, 10);
    enqueue(&q, 13);
    traverse(&q);
}
void enqueue(cqueue *q, int data){
    if((q->rear + 1) % max == q->front ){
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % max;
    q->info[q->rear] = data;
    printf("Enqueued %d\n", data);
}
void dequeue(cqueue *q){
    if(q->front == q->rear){
        printf("Queue is empty\n");
        return;
    }
    q->front = (q->front + 1) % max;
    printf("%d Dequeued\n", q->info[q->front]);
}
void traverse(cqueue *q){
    int i;
    if(q->front == q->rear){
        printf("Queue is empty\n");
        return;
    }
    for(i = (q->front + 1)% max; i != q->rear; i= (i + 1)% max)
        printf("%d ", q->info[i]);
    printf("%d\n", q->info[q->rear]);
}

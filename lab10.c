//WAP to implement array implemented qriority queue
#include<stdio.h>
#define max 5
typedef struct {
    int info[max];
    int front;
    int rear;
} queue;
void enqueue(queue *q, int data);
void dequeue(queue *q);
void traverse(queue *q);
int priority(queue * q);
int main(){
    int i;
    queue q;
    q.front = 0;
    q.rear = -1;
    for(i=0; i<= max; i++){
        enqueue(&q, i);
        traverse(&q);
    }
    for(i=0; i<= max; i++){
        dequeue(&q);
        traverse(&q);
    }
}
void enqueue(queue *q, int data){
    if(q->rear == max -1){
        printf("Queue is full\n");
        return;
    }
    q->info[++q->rear] = data;
    printf("Enqueued %d\n", data);
}
void dequeue(queue *q){
    if(q->front > q->rear){
        printf("Queue is empty\n");
        return;
    }
    int index = priority(q);
    printf("%d Dequeued\n", q->info[index]);
    for(int i = index ; i< q->rear; i++){
        q->info[index]= q->info[index + 1];
    }
    --q->rear;
}
void traverse( queue *q){
    for(int i=q->front; i <= q->rear; i++ ){
        printf("%d ", q->info[i]);
    }
    printf("\n");
}
int priority(queue *q){
    int index = q->front;
    for( int i =q->front; i<q->rear; i++){
        index = (q->info[index] > q->info[index + 1]) ? index : index + 1;
    }
    return index;
}
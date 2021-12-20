#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
}queue;
// create queue
queue* create_queue(int capacity){
    queue *q= malloc(sizeof(queue));
    if(!q)
        {printf("not created");
        return NULL;}
    q->capacity=capacity;
    q->size=0;
    q->front=q->rear=-1;
    q->data= malloc(capacity*sizeof(int));
    return q;
}
// return size
int queue_size(queue *q){
    return q->size;
}
// return front element
int front_element(queue *q){
    if(q->front==-1)
    {
        // printf("Queue is empty");
        return -1;
    }
    return q->data[q->front];
}
// return rear element
int rear_element(queue *q){
    if(q->rear==-1)
    {
        printf("Queue is empty");
        return -1;
    }
    return q->data[q->rear];
}
// is empty
int is_empty(queue *q){
    if (q->size==0)
    return 1;
return 0;
}
// is full
int is_full(queue *q){
    if (q->size==q->capacity)
    return 1;
return 0;
}
// adding element
queue* add_element(queue *q, int n){
    if(is_full(q))
    {
        printf("Queue Is Full");
    }
    else{
        q->rear=(q->rear+1)%q->capacity;
        q->data[q->rear]=n;
        if(q->front==-1)
        {
            q->front=q->rear;
        }
    q->size+=1;
    }
    return q;
}
// delete element
int delete_element(queue *q)
{
    int data=-1111111;
    if(is_empty(q))
    {
        printf("Queue is empty");
        return data;
    }
    data=q->data[q->front];
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
        q->size=0;
    }
    else{
        q->front=(q->front-1)%q->capacity;
        q->size-=1;
    }
    return data;
}

int main(){
    queue *q;
    q =create_queue(5);
    q=add_element(q,5);
    printf("\n%d",queue_size(q));
    return 0;
}
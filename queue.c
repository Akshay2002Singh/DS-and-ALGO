#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct queue
{
    node *front;
    node *rear;
}queue;

queue *create_queue(queue *q){
    q = (queue*) malloc(sizeof(queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}
void push(queue *q , int data){
    node *temp= (node*) malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    if(q->front==NULL&&q->rear==NULL)
    {
        q->front=temp;
        q->rear=temp;
    }
    else{
        q->rear->next=temp;
        q->rear=temp;
    }
    return;
}
int pop(queue *q){
    node *temp;
    int data = -1;
    if(q->front==NULL)
    {
        printf("queue is empty.\n");
    }
    else if (q->front==q->rear)
    {
        temp=q->front;
        data=temp->data;
        q->front=q->rear=NULL;
        free(temp);
    }
    else
    {
        temp=q->front;
        data=temp->data;
        q->front=q->front->next;
        free(temp);
    }
    return data;
}
void display(queue *q){
    node *temp=q->front;
    while (temp!=NULL)
    {
        printf("%d \t",temp->data);
        temp=temp->next;
    }
}
int is_empty(queue *q){
    if(q->front==NULL&&q->rear==NULL)
    return 1;
    else
    return 0;
}
int main(){
    queue *s;
    int condition,data;
    s=create_queue(s);
    while(1){
        printf("Press 1 for push \nPress 2 for pop \nPress 3 for display\nPress 4 to check queue is empty or not \nPress 5 to exit\n");
        printf("Enter option :- ");
        scanf("%d",&condition);
        switch (condition)
        {
        case 1:
            printf("Enter data to push : ");
            scanf("%d",&data);
            push(s,data);
            break;
        case 2:
            data = pop(s);
            printf("Data popped is %d ",data);
            break;
        case 3:
            display(s);
            break;
        case 4:
            is_empty(s)?printf("Yes it is empty"):printf("It is not empty");
            break;
        default:
            printf("Enter correct option");
            break;
        }
    if(condition==5)
    {
        break;
    }
    printf("\n\n");
    }
    return 0;
}
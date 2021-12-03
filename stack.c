#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct stack
{
    node *top;
}stack;

stack *create_stack(stack *s){
    s = (stack*) malloc(sizeof(stack));
    s->top=NULL;
    return s;
}
void push(stack *s , int data){
    node *temp= (node*) malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    if(s==NULL)
    {
        s->top=temp;
    }
    else{
        temp->next=s->top;
        s->top=temp;
    }
    return;
}
int pop(stack *s){
    node *temp;
    int data = -1;
    if(s->top==NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        temp=s->top;
        data=temp->data;
        s->top=s->top->next;
    }
    return data;
}
void display(stack *s){
    node *temp=s->top;
    while (temp!=NULL)
    {
        printf("%d \t",temp->data);
        temp=temp->next;
    }
}
int is_empty(stack *s){
    if(s->top==NULL)
    return 1;
    else
    return 0;
}
int main(){
    stack *s;
    int condition,data;
    s=create_stack(s);
    while(1){
        printf("Press 1 for push \nPress 2 for pop \nPress 3 for display\nPress 4 to check stack is empty or not \nPress 5 to exit\n");
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
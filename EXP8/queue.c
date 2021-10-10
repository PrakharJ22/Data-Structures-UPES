#include<stdio.h>
#include<stdlib.h>

int front=-1;
int rear=-1;
int Q[10];
int cap=10;


void Enqueue(int val)
{
    if((rear+1)%cap==front)
    {
        printf("\nOverflow.....!");
        return;
    }
    else if(rear==-1)
    {
        front=0;
        rear=0;
        Q[rear]=val;
    }
    else
    {
        rear=(rear+1)%cap;
        Q[rear]=val;
    }
    printf("\n%d has been enqueued...!",val);
}


void Dequeue()
{
    if(front==-1)
    {
        printf("\nUnderflow.....!");
        return;
    }
    int temp=front;
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%cap;
    }
    printf("\nElement to be deleted : %d",Q[temp]);
    Q[temp]=0;
}


void display()
{
    if(front==-1 )
    {
        printf("\nOverflow condition....!");
        return;
    }
    int i;
    printf("\nQ elements are : ");
    for( i=front;i!=rear;i=(i+1)%cap)
    printf("%d ",Q[i]);
    printf("%d",Q[i]);
}

int main()
{
    Enqueue(1);
    Dequeue();
    Dequeue();
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Enqueue(6);
    Enqueue(7);
    Enqueue(8);
    Enqueue(9);
    Enqueue(10);
    Enqueue(11);
    display();
    return 0;
}
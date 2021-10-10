
#include <stdio.h>
#include<stdlib.h>
#define SIZE 7

int stack1[SIZE];
int stack2[SIZE];

int top1=-1;
int top2=-1;

//to push an element into the queue
void enqueue()
{

    if(top1==SIZE-1)
    {
        printf("Overflow");
        return;
    }
    int x;
    printf("\nEnter the element : ");
    scanf("%d",&x);
    if(top1==-1)
    {
        top1=0;
        stack1[top1]=x;
    }
    else
    {
        top2=0;
        while(top1!=-1)
        {
            stack2[top2]=stack1[top1];
            top1--;
            top2++;
        }
        stack2[top2]=x;
        top1=0;
        while(top2!=-1)
        {
            stack1[top1]=stack2[top2];
            top1++;
            top2--;
        }
        top1--;
    }
}


//to dequeue an element from the queue
void dequeue()
{
    if(top1==-1)
    {
        printf("Underflow Condition\n");
        return;
    }
    printf("\nThe Dequeued element from Queue is : %d",stack1[top1]);
    top1--;
}

//to display the queue
void display()
{
    if(top1==-1)
    {
        printf("\nUnderflow......!");
        return;
    }
    printf("\nElements of Queue are : ");
    int i=top1;
    while(i!=-1)
    {
        printf("%d ", stack1[i]);
        i--;
    }
}



int main()
{
    int n;
    char ch;

    l1:
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Display");
    printf("\nEnter your choice (1-3) : ");
    scanf("%d",&n);
    
    switch(n)
    {
        case 1 :    enqueue();
                    break;
        case 2 :    dequeue();
                    break;
        case 3 :    display();
                    break;
        default:    printf("\nInvalid Input.....!");
                    break;
    }
    printf("\nDo you want to perform more operation? (y/n) : ");
    while(getchar()!='\n');
    scanf("%c",&ch);
    if(ch=='y' || ch=='Y')
    goto l1;
    
    
    return 0;   

}


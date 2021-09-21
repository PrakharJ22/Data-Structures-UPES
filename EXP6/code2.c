//2. Using linked list implement Stack and its operations like insert, delete, and display.
#include<stdlib.h>
#include<stdio.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *top=0;

//to insert element into the stack
void push()
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element : ");
    scanf("%d",&ptr->data);
    printf("\nElement pushed successfully....!");
    ptr->next=top;
    top=ptr;
}

//to delete the last element inserted into the stack
void pop()
{
    if(top==NULL)
    {
        printf("\nThe stack is empty.....!");
    }
    else
    {
        struct node *temp;
        printf("\nThe popped element is : %d",top->data);
        temp=top;
        top=top->next;
        free(temp);
    }
}

//to display the stack
void display()
{
    if(top==NULL)
    {
        printf("\nThe stack is empty...!");
    }
    else
    {
        struct node *ptr;
        printf("\nElements of the stack are : \n");
        for(ptr=top;ptr!=0;ptr=ptr->next)
        {
            printf("\t%d\n",ptr->data);
        }
    } 
}

int main()
{
    int n;
    char ch;
    l1:
    printf("\nFollowing operations can be performed");
    printf("\n1. Push");
    printf("\n2. Pop");
    printf("\n3. Display");
    printf("\nEnter your choice : ");
    scanf("%d",&n);

    switch(n)
    {
        case 1 : push();
                 break;
        case 2 : pop();
                 break;
        case 3 : display();
                 break;
        default : printf("\nINVALID INPUT.....!");
                 break;
    }
    printf("\nDo you want to perform more operations? (y/n) : ");
    while(getchar()!='\n');
    scanf("%c",&ch);
    if(ch=='y' || ch=='Y')
    goto l1;
    return 0;
}

/*
#include<stdlib.h>
#include<stdio.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *top=0;

//to insert element into the stack
void push()
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element : ");
    scanf("%d",&ptr->data);
    printf("\nElement pushed successfully....!");
    ptr->next=top;
    top=ptr;
}

//to delete the last element inserted into the stack
void pop()
{
    if(top==NULL)
    {
        printf("\nThe stack is empty.....!");
    }
    else
    {
        struct node *temp;
        printf("\nThe popped element is : %d",top->data);
        temp=top;
        top=top->next;
        free(temp);
    }
}

//to display the stack
void display()
{
    if(top==NULL)
    {
        printf("\nThe stack is empty...!");
    }
    else
    {
        struct node *ptr;
        printf("\nElements of the stack are : \n");
        for(ptr=top;ptr!=0;ptr=ptr->next)
        {
            printf("\t%d\n",ptr->data);
        }
    } 
}

int main()
{
    int n;
    char ch;
    l1:
    printf("\nFollowing operations can be performed");
    printf("\n1. Push");
    printf("\n2. Pop");
    printf("\n3. Display");
    printf("\nEnter your choice : ");
    scanf("%d",&n);

    switch(n)
    {
        case 1 : push();
                 break;
        case 2 : pop();
                 break;
        case 3 : display();
                 break;
        default : printf("\nINVALID INPUT.....!");
                 break;
    }
    printf("\nDo you want to perform more operations? (y/n) : ");
    while(getchar()!='\n');
    scanf("%c",&ch);
    if(ch=='y' || ch=='Y')
    goto l1;
    return 0;
}
*/
/*
#include<stdlib.h>
#include<stdio.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *top=0;

//to insert element into the stack
void push(int n)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=n;
    printf("\nElement %d pushed successfully....!",ptr->data);
    ptr->next=top;
    top=ptr;
}

//to delete the last element inserted into the stack
void pop()
{
    if(top==NULL)
    {
        printf("\nThe stack is empty.....!");
    }
    else
    {
        struct node *temp;
        printf("\nThe popped element is : %d",top->data);
        temp=top;
        top=top->next;
        free(temp);
    }
}

//to display the stack
void display()
{
    if(top==NULL)
    {
        printf("\nThe stack is empty...!");
    }
    else
    {
        struct node *ptr;
        printf("\nElements of the stack are : \n");
        for(ptr=top;ptr!=0;ptr=ptr->next)
        {
            printf("\t%d\n",ptr->data);
        }
    } 
}

int main()
{
    push(1);
    push(2);
    push(3);
    display();
    pop();
    display();
    return 0;
}
*/
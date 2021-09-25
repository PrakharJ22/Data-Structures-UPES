#include<stdio.h>
#include<stdlib.h>

struct node 
{
    char ch;
    struct node *next;
};

void display(struct node *top)
{
    if(top==NULL)
    {
        printf("\nThe stack is empty.....!");
    }
    else
    {
        struct node* ptr;
        printf("\nReversed string is : ");
        for(ptr=top;ptr!=NULL;ptr=ptr->next)
        {
            printf("%c",ptr->ch);
        }
    } 
}


int main()
{
    char string[40];
    int i=0;
    struct node *top=NULL,*ptr=NULL;
    printf("\nEnter the string : ");
    scanf("%s",string);

    while(string[i]!='\0')
    {
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->ch=string[i];
        ptr->next=top;
        top=ptr;
        i++;
    }
    display(top);
    printf("\n");
    return 0;
}
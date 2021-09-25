#include<stdio.h>
#include<stdlib.h>

struct node 
{
    char ch;
    struct node *next;
};


int main()
{
    char string[40];
    int i=0,check=1;
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
    ptr=top;
    for(i=0;ptr!=NULL;ptr=ptr->next,i++)
    {
        if(string[i]!=ptr->ch)
        {
            printf("\nEntered string is not palindrome!");
            check=0;
            return 0;
        }
    }
    if(check==1)
    {
        printf("\nEntered string is palindrome!");
    }
    return 0;
}








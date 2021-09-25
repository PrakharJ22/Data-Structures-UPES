#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
   int data;
   struct node * next; 
};

struct node * stack=NULL, *top=NULL;

void push(int n)
{
    if(stack==NULL)
    {
        struct node * new;
        new=(struct node*)malloc(sizeof(struct node));
        new->data=n;
        stack=new;
        top=stack;
    }
    else
    {
         struct node * new;
         new=(struct node*)malloc(sizeof(struct node));
         new->data=n;
         new->next=top;
         top=new;

    }
}
int pop()
{
    if(stack==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        int d;
        struct node * temp;
        temp=top;
        top=top->next;
        d=temp->data;
        free(temp);   
        return d;  
    }
}

int main()
{
    char exp[30], ele[2];
    printf("Enter Postfix expression: ");
    scanf("%s",exp);
    exp[strlen(exp)]='\0';
    for(int i=0; i<strlen(exp); i++)
    {
        int res, a, b;
        if(exp[i]!=',')
        {
            if(exp[i]=='+')
            {
                res=pop();
                res+=pop();
                push(res);
            }
            else if(exp[i]=='-')
            {
                a=pop();
                b=pop();
                res=b-a;
                push(res);
            }
            else if(exp[i]=='*')
            {
                res=pop()*pop();
                push(res);
            }
            else if(exp[i]=='/')
            {
                a=pop();
                b=pop();
                res=b/a;
                push(res);
            }
            else
            {
                if(exp[i+1]!=',')
                {
                    ele[0]=exp[i];
                    res=atoi(ele);
                    ele[0]=exp[i+1];
                    i++;
                    res=res*10+atoi(ele);
                    push(res);
                }
                else
                {
                    ele[0]=exp[i];
                    res=atoi(ele);
                    push(res);
                }
            }
        }
    }
    printf("Result : %d\n",pop());
    return 0;
}
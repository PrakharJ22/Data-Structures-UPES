/*1. Implement Doubly Linked List and its operations.  
*/

#include<stdio.h>
#include<stdlib.h>  //for malloc() and free()

struct node 
{
    int number;
    struct node *prev;
    struct node *next;
};

struct node *head=0,*tail=0;    

//to create a doubly linked list
void create()
{
    struct node *ptr;
    char ch;
    l1:
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&ptr->number);
    ptr->next=NULL;
    ptr->prev=NULL;

    if(head==NULL)
    {
        head=ptr;
        tail=ptr;
    }
    else
    {
        tail->next=ptr;
        ptr->prev=tail;
        tail=ptr;
    }
    printf("\nDo you want to add more elements in the list? (y/n) : ");
    while(getchar()!='\n');
    scanf("%c",&ch);
    if(ch=='y' || ch=='Y')
    goto l1;
    
}

//to insert at beginning
void insert_beg()
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted at the beginning : ");
    scanf("%d",&new->number);
    new->next=0;
    new->prev=0;
    if(head==0)
    {
        head=new;
        tail=new;
    }
    else
    {
        head->prev=new;
        new->next=head;
        head=new;
    } 
}

//to insert at the end
void insert_end()
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to be inserted at the end : ");
    scanf("%d",&new->number);
    new->prev=0;
    new->next=0;
    if(head==0)
    {
        head=new;
        tail=new;
    }
    else
    {
        new->prev=tail;
        tail->next=new;
        tail=new;
    }  
}

//to insert at the random position
void insert_pos()
{
    struct node *new,*ptr,*temp;
    int pos,i=1;
    printf("\nEnter the position where you have to insert : ");
    scanf("%d",&pos);
    if(pos==1)
    {
        insert_beg();
    }
    else
    {
        ptr=head;
        while(i<pos-1)
        {
            ptr=ptr->next;
            i++;
        }
        if(ptr->next==0) 
        {
            insert_end();
        }
        else
        {
            new=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter the data : ");
            scanf("%d",&new->number);

            temp=ptr->next;
            ptr->next->prev=new;
            new->prev=ptr;
            ptr->next=new;
            new->next=temp;
        }
    }
}

//to delete the first element of the doubly linked list
void delete_beg()
{
    if(head==0)
    {
        printf("\nDoubly Linked List is empty...!");
    }
    else
    {
        struct node *temp;
        temp=head;
        head->next->prev=0;
        head=head->next;
        free(temp);
    }  
}

//to delete the last node of doubly linked list
void delete_end()
{
    if(head==0)
    {
        printf("\nDoubly Linked List is empty....!");
    }
    else
    {
        struct node *temp;
        temp=tail;
        tail->prev->next=NULL;
        tail=tail->prev;
        free(temp);
    } 
}

//to delete the node at any position
void delete_pos()
{
    struct node *ptr,*temp,*temp2;
    int pos,i=1;
    printf("\nEnter the position where you have to delete : ");
    scanf("%d",&pos);
    if(pos==1)
    {
        delete_beg();
    }
    else
    {
        ptr=head;
        while(i<pos-1)
        {
            ptr=ptr->next;
            i++;
        }
        if(ptr->next==0) 
        {
            delete_end();
        }
        else
        {
            temp=ptr->next;
            temp2=ptr->next->prev;
            ptr->next=ptr->next->next;
            ptr->next->prev=temp2;
            free(temp);
        }
    }
}

//to display the doubly linked list
void display()
{
    if(head==0)
    {
        printf("\nThe Doubly Linked List is EMPTY....!");
    }
    else
    {
        struct node *ptr;
        printf("\nElements of the Doubly Linked List : \n");
        for(ptr=head;ptr!=0;ptr= ptr->next)
        printf("\t%d\n",ptr->number);
    } 
}

//to free the doubly linked list
void free_linked_list() 
{
    while (head) 
    {
       struct node* temp = head;
        head = head->next;

        free(temp);
    }
}


//main() function 
int main()
{
    int n;
    char var;
    l2:
    printf("\nFollowing functions can be performed : ");
    printf("\n1. Create a doubly linked lists");
    printf("\n2. Insertion at the beginning");
    printf("\n3. Insertion at the end");
    printf("\n4. Insertion at a given position");
    printf("\n5. Deletion at the beginning");
    printf("\n6. Deletion at the end");
    printf("\n7. Deletion at the given position");
    printf("\n8. Display the doubly linked lists from head");
    printf("\nEnter your choice (1-8): ");
    scanf("%d",&n);

    switch(n)
    {
        case 1 : create();
                 printf("\nDoubly Linked list is created...!");
                 break;
        case 2 : insert_beg();
                 printf("\nElement inserted at the beginning successfully....!");
                 break;
        case 3 : insert_end();
                 printf("\nElement inserted at the end....!");
                 break;
        case 4 : insert_pos();
                 printf("\nElement is inserted at desired position...!");
                 break;
        case 5 : delete_beg();
                 printf("\nBeginning element is at deleted.....!");
                 break;
        case 6 : delete_end();
                 printf("\nLast element is deleted....!");
                 break;
        case 7 : delete_pos();
                 printf("\nElement is deleted.....!");
                 break;
        case 8 : display();
                 break;
        default : printf("\nINVALID INPUT.....!");
    }
    printf("\nDo you want to perform more operations? (y/n) : ");
    while(getchar()!='\n');
    scanf("%c",&var);
    if(var=='y' || var=='Y')
    goto l2;
    free_linked_list();
    return 0;
}

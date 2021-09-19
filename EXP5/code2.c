/*
2. Implement single Linked List data structure for student and its operations like insert 
and delete in the beginning/end and nth position of the list, and display the items stored 
in the linked list
*/


#include<stdio.h>
#include<stdlib.h>

struct student
{
    int Sap;
    char name[50];
    int total_marks;
    struct student *next;
};

struct student *create_node()
{
    struct student *head=0,*ptr;
    l1:
    if(head==0)
    {
        printf("Creating a node...!\n");
        head=(struct student*)malloc(sizeof(struct student));
        printf("Enter the SAP ID : ");
        scanf("%d",&head->Sap);
        printf("Enter the name : ");
        while(getchar()!='\n');
        fgets(head->name,50,stdin);
        printf("Enter the total marks : ");
        scanf("%d",&head->total_marks);
        ptr=head;
    }
    else
    {
        ptr->next=(struct student*)malloc(sizeof(struct student));
        ptr=ptr->next;
        printf("Enter the SAP ID : ");
        scanf("%d",&ptr->Sap);
        printf("Enter the name : ");
        while(getchar()!='\n');
        fgets(ptr->name,50,stdin);
        printf("Enter the total marks : ");
        scanf("%d",&ptr->total_marks);
    }
    char check;
    printf("Do you want to enter more elements in the lists? (y/n) : ");
    while(getchar()!='\n');
    scanf("%c",&check);
    if(check=='y' || check=='Y')
        goto l1;
    ptr->next=NULL;
    return head;
}

//to insert at the end
struct student *insertion_end(struct student *head)
{
    struct student *ptr,*temp;
    if(head==0)
    {
        printf("The list is empty!");
    }
    else
    {
        ptr=(struct student*)malloc(sizeof(struct student));
        printf("Enter the SAP ID : ");
        scanf("%d",&ptr->Sap);
        printf("Enter the name : ");
        while(getchar()!='\n');
        fgets(ptr->name,50,stdin);
        printf("Enter the total marks : ");
        scanf("%d",&ptr->total_marks);
        ptr->next=NULL;

        for(temp=head;temp->next!=0;temp=temp->next);
        temp->next=ptr;
    }
    return head;
}

struct student *insertion_beg(struct student *head)
{
    struct student *ptr,*temp;
    if(head==0)
    {
        printf("\nThe list is empty!");
    }
    else
    {
        ptr=(struct student*)malloc(sizeof(struct student));
        printf("Enter the SAP ID : ");
        scanf("%d",&ptr->Sap);
        printf("Enter the name : ");
        while(getchar()!='\n');
        fgets(ptr->name,50,stdin);
        printf("Enter the total marks : ");
        scanf("%d",&ptr->total_marks);
        temp=head;
        head=ptr;
        ptr->next=temp;
    }
    return head;
}

struct student *insertion_nth(struct student *head)
{
    struct student *ptr,*new1,*temp;
    int num,count=0,i=1;
    if(head==0)
    {
        printf("The linked list is empty!");
    }
    else 
    {
        printf("\nEnter the position where you have to insert the new node : ");
        scanf("%d",&num);
        if(num==1)
        head=insertion_beg(head);
        else
        {
            ptr=head;
            while(i<num-1)
            {
                ptr=ptr->next;
                i++;
            }
            if(ptr->next==0)            //traversed to end-of list
            head=insertion_end(head);
            else                        //traversed to a node in middle of list
            {
                new1=(struct student*)malloc(sizeof(struct student));
                printf("Enter the SAP ID : ");
                scanf("%d",&new1->Sap);
                printf("Enter the name : ");
                while(getchar()!='\n');
                fgets(new1->name,50,stdin);
                printf("Enter the total marks : ");
                scanf("%d",&new1->total_marks);

                temp=ptr->next;
                ptr->next=new1;
                new1->next=temp;
            }
        }   
    }
    return head;
}

struct student* deletion_beg(struct student* head)
{
    struct student* temp;
    if(head==0)
    {
        printf("The list is empty!");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    return head;
}

struct student *deletion_end(struct student* head)
{
    struct student *ptr,*temp,*temp2;
    int count=0;
    if(head==0)
    {
        printf("The list is empty!");
    }
    else
    {
        for(temp=head;temp!=0;temp=temp->next)
        count++;

        printf("Deleting last node");
        int i=1;
        for(ptr=head;i<count-1;ptr=ptr->next,i++);
        temp2=ptr->next;
        ptr->next=NULL;
        free(temp2);
    }
    return head;   
}

struct student *deletion_nth(struct student* head)
{
   struct student *ptr,*temp;
    int pos;
    if(head==0)
    {
        printf("The list is empty!");
    }
    else
    {
        printf("Enter the position : ");
        scanf("%d",&pos);
        if(pos==1)
        {
            head=deletion_beg(head);
        }
        else
        {
            printf("\nDeleting %dth node!",pos);
            int i=1;
            for(ptr=head;i<pos-1;ptr=ptr->next,i++);
            if(ptr->next==NULL)
            {
                head=deletion_end(head);
            }
            else
            {
                temp=ptr->next;
                ptr->next=ptr->next->next;
                free(temp);
            } 
        }
    }
    return head;    
}

//to display the student details 
void display(struct student *head)
{
    if(head==0)
    {
        printf("\nThe linked list for student is empty...!");
    }
    else
    {
        struct student *ptr;
        int count=1;
        for(ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            printf("\n\nDetail of the student %d : ",count);
            printf("\nSAP ID : %d",ptr->Sap);
            printf("\nName : %s",ptr->name);
            printf("Total marks : %d",ptr->total_marks);
            count++;
        }
    }
}

int main()
{
    struct student *head=0,*ptr,*tail;
    int n;
    char check;
    l2 :
    printf("\nFunctions that this program has :  ");
    printf("\n1. Create a Linked list");
    printf("\n2. Insertion at the end");
    printf("\n3. Insertion at the beginning");
    printf("\n4. Insertion at nth position ");
    printf("\n5. Deletion at the end");
    printf("\n6. Deletion at nth position.");
    printf("\n7. Deletion at the beginning");
    printf("\n8. Display of the linked list");
    printf("\nChoose what functions you want to execute (1-8) : ");
    scanf("%d",&n);
    
    switch(n)
    {
        case 1 : head=create_node();
                 break;
        case 2 : head=insertion_end(head);
                 break;
        case 3 : head=insertion_beg(head);
                 break;
        case 4 : head=insertion_nth(head);
                 break;
        case 5 : head=deletion_end(head);
                 break;
        case 6 : head=deletion_nth(head);
                 break;
        case 7 : head=deletion_beg(head);
                 break;
        case 8 : display(head);
                 break;
        default : printf("Program has been ended!");
                 break;
    }

    printf("\nDo you want to perform more operations? (y/n): ");
    while(getchar()!='\n');
    scanf("%c",&check);
    if(check=='y' || check=='Y')
    goto l2;
    return 0;
}
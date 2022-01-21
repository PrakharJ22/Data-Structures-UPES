#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
int HashTable[SIZE]={0};
int count=0;

int HashFunction(int key)
{
    return key%SIZE;
}

void insert(int key)
{
    if(count==SIZE)
    {
        printf("\nThe Hash Table has been filled......!");
        return;
    }
    else
    {
        int index=HashFunction(key);
        if(HashTable[index]==0)
        {
            HashTable[index]=key;
            printf("\nKey %d is inserted.....!",key);
            count++;
        }
        else
        {
            int i=1;
            while(HashTable[index]!=0)
            {
                index=(index+i*i)%SIZE;
                i++;
            }
            HashTable[index]=key;
            printf("\nKey %d is inserted.....!",key);
            count++;
        }
    }
}

void search(int key)
{
    if(count==0)
    {
        printf("\nHash table is empty....!");
        return;
    }
    int index=HashFunction(key);
    if(HashTable[index]==key)
    {
       printf("\nKey %d is found at index : %d ",key,index);
    }
    else
    {
        int i=1;
        while(HashTable[index]!=key && HashTable[index]!=0)
        {
            index=(index+i*i)%SIZE;
            i++;
        }
        if(HashTable[index]==0)
        {
            printf("\nKey %d not found......!",key);
            return;
        }
        else
            printf("\nKey %d is found at index : %d ",key,index);
    }
}

void deletion(int key)
{
    if(count==0)
    {
        printf("\nHash table is empty.....!");
        return;
    }
    int index=HashFunction(key);
    if(HashTable[index]==key)
    {
        HashTable[index]=0;
        printf("\nKey %d is been deleted.....!",key);
        count--;
    }
    else
    {
        int i=1;
        while(HashTable[index]!=key && HashTable[index]!=0)
        {
            index=(index+i*i)%SIZE;
            i++;
        }
        if(HashTable[index]==key)
        {
            HashTable[index]=0;
            printf("\nKey %d is been deleted.....!",key);
            count--;
        }
        else
        {
            printf("\nElement not found....!");
        }
    }
}

void display()
{
    if(count==0)
    {
        printf("\nHash Table is empty....!");
    }
    for(int i=0;i<SIZE;i++)
    {
        printf("\n%d : %d ",i,HashTable[i]);
    }
}

int main()
{ 
    int n;
    int key;
    char ch;
    l1:
    printf("\n1. Insert");
    printf("\n2. Search");
    printf("\n3. Display");
    printf("\n4. Delete");
    printf("\nEnter your choice : ");
    scanf("%d",&n);
    switch(n)
    {
        case 1 :    printf("\nEnter the value you have to insert : ");
                    scanf("%d",&key);
                    insert(key);
                    break;
        case 2 :    printf("\nEnter the value you want to search : ");
                    scanf("%d",&key);
                    search(key);
                    break;
        case 3 :    printf("\nHash Table : \n");
                    display();
                    break;
        case 4 :    printf("\nEnter the value you want to delete : ");
                    scanf("%d",&key);
                    deletion(key);
                    break;
        default :   printf("\nInavlid input....!");
                    break;
    }
    printf("\nDo you want to perform more? (y/n) : ");
    while(getchar()!='\n');
    scanf("%c",&ch);
    if(ch=='y' || ch=='Y')
    goto l1;
}
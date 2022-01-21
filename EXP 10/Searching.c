#include<stdio.h>
void bubble_sort(int a[10],int n)
{
    int  i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int array[10],i,n,data,found=0;
    printf("\nEnter the size of the array : ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array : \n");
    for(i=0;i<n;i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&array[i]);
    }

    printf("\nEnter the data to be search for : ");
    scanf("%d",&data);
    for(i=0;i<n;i++)
    {
        if(array[i]==data)
        {
            printf("\nIn Linear Searching :\nThe data is found at index : %d \nNumber of comparisons made : %d",i,i+1);
            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("\nElement not found.....!");
        return 0;
    }
    bubble_sort(array,n);
    int beg,end,mid,counter=0;
    beg=0;
    end=n-1;
    mid=(beg+end)/2;
    while(beg<=end)
    {
        if(array[mid]==data)
        {
            printf("\nIn Binary searching :\nData is found at index : %d\nNumber of comparisons made : %d",mid,counter);
            break;
        }
        else if(array[mid]>data)
        {
            end=mid-1;
            mid=(beg+end)/2;
            counter++;
        }
        else
        {
            beg=mid+1;
            mid=(beg+end)/2;
            counter++;
        } 
    }
    return 0;
}
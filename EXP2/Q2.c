//2. Find out the largest and smallest number in a given array

#include<stdio.h>
int main()
{
    int array[50],min,max,i,size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    printf("Enter the elements of the array : \n");
    for(i=0;i<size;i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&array[i]);
    }
    max=array[0];
    for (i=1;i<size;i++)
    {
        if(max<array[i])
        {
            max=array[i];
        }
    }

    min=array[0];
    for(i=0;i<size;i++)
    {
        if(min>array[i])
        {
            min=array[i];
        }
    }
    
    printf("The biggest number in the array is : %d\n",max);
    printf("The smallest number in the array is : %d",min);
    return 0;
}
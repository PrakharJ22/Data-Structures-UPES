/**
 * 3. Store ‘n’ numbers (integers or real) in an array in ascending or descending order. 
 * Conduct a binary search for a given number and report success or failure in the form of a 
 * suitable message.
 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int array_num[50],m, n,number;
    printf("\nEnter the array size (n) : ");
    scanf("%d",&n);    //getting the size of the array
    
    if(n<1)
    {
        printf("Array size cannot be less than 1!");
    }
    else
    {
        printf("Enter the elements of the array (in descending order) : \n");
        for(m=0;m<n;m++)
        {
            printf("Enter the element %d : ",m);
            scanf("%d",&array_num[m]);   //getting the array elements from the user        
        }
        printf("\nEnter the number to be searched for : ");
        scanf("%d",&number);         //getting the element to be searched for in the array
    
        int start=0,end =n-1,mid;   //variables for binary searching
    
        while (start<=end)   //binary searching
        {
            mid=(start+end)/2;
            if(number>array_num[mid])
            {
                end = mid-1;
            }
            else if(number==array_num[mid])
            {
                printf("The element %d is found at index %d!",number,mid);    
                exit (0);
            }
            else
            {
                start=mid+1;    
            }
        }
        if(start>end)
        {
            printf("\nEntered element not found....!");
        }
    }
  
    return 0;   
}


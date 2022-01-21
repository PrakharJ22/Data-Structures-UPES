

#include<stdio.h>
#define N 10

void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}

void insertion_sort(int a[10],int n)
{
  int i,j,temp;
  for(i=1;i<n;i++)
  {
    temp=a[i];
    j=i-1;
    while(j>=0 && a[j]>temp)
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=temp;
  }
}

void selection_sort(int a[10],int n)
{
  int i,j,min,temp;
  for(i=0;i<n-1;i++)
  {
    min=i;
    for(j=i+1;j<n;j++)
    {
      if(a[min]>a[j])
      {
        min=j;
      }
    }
    if(min!=i)
    {
      swap(&a[i],&a[min]);
    }
  }
}

void bubble_sort(int a[10],int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1-i;j++)
    {
      if(a[j]>a[j+1])
      {
        swap(&a[j],&a[j+1]);
      }
    }
  }
}

int main()
{
  int Array1[N]={7,6,5,8,9,4,3,2,1,8};
  int Array2[N]={5,4,6,3,7,9,1,2,5,7};
  int Array3[N]={7,5,6,4,8,3,6,1,3,2};
  printf("\nBefore Sorting : \nArray 1 is : ");
  for(int i=0;i<N;i++)
    printf("%d ",Array1[i]);
  
  printf("\nArray 2 is : ");
  for(int i=0;i<N;i++)
    printf("%d ",Array2[i]);
  
  printf("\nArray 3 is : ");
  for(int i=0;i<N;i++)
    printf("%d ",Array1[i]);
  
  insertion_sort(Array1,N);
  selection_sort(Array2,N);
  bubble_sort(Array3,N);
  
  printf("\nAfter using Insertion sort : \nArray 1 is : ");
  for(int i=0;i<N;i++)
    printf("%d ",Array1[i]);

  printf("\nAfter using selection sort : \nArray 2 is : ");
  for(int i=0;i<N;i++)
    printf("%d ",Array2[i]);

  printf("\nAfter using Bubble sort) :\nArray 3 is : ");
  for(int i=0;i<N;i++)
    printf("%d ",Array3[i]);
  
  return 0;
}




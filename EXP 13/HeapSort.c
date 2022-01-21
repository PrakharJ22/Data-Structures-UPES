
#include<stdio.h>
#include<stdlib.h>
void Print(int *arr,int n);
struct MaxHeap
{
    int *array;
    int size;
};

void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}

void Heapify(struct MaxHeap *Heap, int i)
{
    int largest=i;
    int left,right;
    left=2*i+1;
    right=2*i+2;
    if(left<Heap->size && Heap->array[left]>Heap->array[i])
    {
        largest=left;
    }
    if(right<Heap->size && Heap->array[right]>Heap->array[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(&Heap->array[i],&Heap->array[largest]);
        Heapify(Heap, largest);
    }
   
}

void HeapSort(int *array,int n)
{
    struct MaxHeap *Heap=(struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    Heap->array=array;
    Heap->size=n;
    for(int i=(n-2)/2;i>=0;i--)
    {
        Heapify(Heap,i);

    }
    printf("\nIntermediate Array : \n");
    Print(array,n);
    while(Heap->size > 1)
    {
        swap(&Heap->array[0],&Heap->array[Heap->size-1]);
        Heap->size=Heap->size-1;
        Heapify(Heap,0);
    }
}


void Print(int *arr,int n)
{
    int i;
    for(int i=0;i<n;i++)
        printf("\t%d",arr[i]);

}

int main()
{
    int array[]={15,19,13,20,14,11};
    int n=sizeof(array)/sizeof(array[0]);
    /*
                 15
            19        13
         20   14    11 

    */
   printf("\nArray : \n");
   Print(array,n);
   HeapSort(array,n);
   printf("\nAfter Sorting : \n");
   Print(array,n);
   return 0;
}



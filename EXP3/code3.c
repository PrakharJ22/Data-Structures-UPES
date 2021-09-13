//3. Find the product of two matrices using pointers.
#include<stdio.h>
int main()
{
    int a[5][5],b[5][5],c[5][5],m,n,p,q,i,j,k;
    printf("\nEnter the rows of the matrix a (max 5): ");
    scanf("%d",&m);
    printf("Enter the columns of the matrix a (max 5): ");
    scanf("%d",&n);
    printf("Enter the rows of the matrix b (max 5): ");
    scanf("%d",&p);
    printf("Enter the columns of the matrix b (max 5): ");
    scanf("%d",&q);
    
    if(n==p)
    {
        printf("Enter the elements of the matrix a:\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("Enter the element at index [%d][%d] : ",i,j);
                scanf("%d",(*(a+i)+j));
            }
        }
        printf("\nEnter the elements of the matrix b :\n");
        for(i=0;i<p;i++)
        { 
            for(j=0;j<q;j++)
            {
                printf("Enter the elements at index [%d][%d] : ",i,j);
                scanf("%d",(*(b+i)+j));
            }
        }
        printf("The matrix a is:\n");
        for(i=0;i<m;i++)
        {
            for (j=0;j<n;j++)   
            {
                printf("%d ",*(*(a+i)+j));
            }
            printf("\n");
        }
        printf("The matrix b is:\n");
        for(i=0;i<p;i++)
        {
            for(j=0;j<q;j++)
            {
                printf("%d ",*(*(b+i)+j));
            }
            printf("\n");
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
                *(*(c+i)+j) = 0;
                for(k=0;k<n;k++)
                {
                    *(*(c+i)+j) = *(*(c+i)+j) + (*(*(a+i)+k) * *(*(b+k)+j));
                }
            }
        }
        printf("The multiplication of matrix a and b is:\n");
        for(i=0;i<p;i++)
        {
            for (j=0;j<q;j++)
            {
                printf("%d ",*(*(c+i)+j));
            }
            printf("\n");
        }
    }
    else 
        printf("Sorry the matrix cannot be multipied !!"); 
    return 0;
}

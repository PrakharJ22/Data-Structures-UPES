//1. Find the Transpose and Inverse of a matrix
#include<stdio.h>
int main()
{
    int a[3][3];
    printf("Enter the elements of the matrix : \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter the element at index [%d][%d] : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("The input matrix is : \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("The transpose of the matrix : \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    float determinant=0;
  for(int i=0;i<3;i++)
      determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));

   printf("\nInverse of matrix is: \n\n");
   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++)
           printf("%.2f\t",((a[(i+1)%3][(j+1)%3] * a[(i+2)%3][(j+2)%3]) - (a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]))/ determinant);
       printf("\n");
   }
    return 0;
}
//1. Add two complex numbers by passing structure to a function as argument.

#include<stdio.h>

struct complex   //definning the structure 
{
    int real;
    int img;
};

void add(struct complex var1,struct complex var2)     //function to add two complex numbers 
{
    printf("\nComplex num 1 : %d+%di",var1.real,var1.img);
    printf("\nComplex num 2 : %d+%di",var2.real,var2.img);
    printf("\nSum : %d+%di",var1.real+var2.real,var1.img+var2.img);
}

int main()
{
    struct complex var1,var2;
    printf("\nEnter the first complex number : ");
    printf("\nEnter the real part : ");
    scanf("%d",&var1.real);
    printf("Enter the imaginary part : ");
    scanf("%d",&var1.img);

    printf("\nEnter the second complex number : ");
    printf("\nEnter the real part : ");
    scanf("%d",&var2.real);
    printf("\nEnter the imaginary part : ");
    scanf("%d",&var2.img);

    add(var1,var2);
    return 0;
}
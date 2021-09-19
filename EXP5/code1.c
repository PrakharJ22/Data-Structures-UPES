/*1. Design a structure ‘subject’ to store the details of the subject like subject name 
and subject code. Using structure pointer allocate memory for the structure dynamically so as to obtain 
details of ‘n’ subjects using for loop.
*/

#include<stdio.h>
#include<stdlib.h>
struct subject
{
    char name[50];
    int code;
} *sub ;
int main()
{
    int i,n;
    printf("\nEnter the number of subjects whose details have to be stored : ");
    scanf("%d",&n);
    sub = (struct subject*)malloc(n*sizeof(struct subject));
    for(i=0;i<n;i++)
    {
        printf("\n Enter the details of the Subject %d ",i+1);
        printf("\n Enter the name of the subject : ");
        while(getchar()!='\n');
        fgets((sub+i)->name,50,stdin);
        printf(" Enter the code of the subject : ");
        scanf("%d",&(sub+i)->code);
    }

    printf("\n\t\tSubject Records");
    for(i=0;i<n;i++)
    {
        printf("\n\tSubject %d\n\tName = %s",i+1,(sub+i)->name);
        printf("\tSubject code = %d\n",(sub+i)->code);
    }
   return 0;
}

//2.  Count the number of words in a string.
#include <stdio.h>
#include <string.h>
int main()
{
    int count=1;
    char string[30];
   
    printf("Enter the string : ");
    fgets(string,30,stdin);
   for(int i=0;i<strlen(string);i++)
   {
       if(string[i]==' ')
       {
           count++;
       }
   }
   printf("Number of words in the string : %d",count);
    return 0;
}
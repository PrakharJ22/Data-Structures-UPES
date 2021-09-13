//1. Find whether the entered string is palindrome or not.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char string[50];
    int j,check=0;
    printf("Enter the string : ");
    scanf("%s",string);
    j=strlen(string)-1;
    for(int i=0;i<strlen(string);i++)
    {
        if(string[i]==string[j])
        {
            check=1;
        }
        else
        {    
            printf("The given string is not palindrome!");
            exit(0);
        }
        j--;
    }
    if(check==1)
    {
        printf("The given string is palindrome!");
    }
   
    return 0;
}

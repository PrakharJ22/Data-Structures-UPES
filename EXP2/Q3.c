//3. Find the total number of alphabets, digits or special characters in a string.
#include<stdio.h>
#include<string.h>
int main()
{
    char string[50];
    int alpha_count=0,digit_count=0,special_char_count=0;
    printf("Enter the string : ");
    fgets(string,50,stdin);
    for(int i=0;i<strlen(string)-1;i++)
    {
        if(((string[i]>=65)&&(string[i]<=90))||((string[i]>=97)&&(string[i]<=122)))
        {
            alpha_count++;
        }
        else if((string[i]>=48)&&(string[i]<=57))
        {
            digit_count++;
        }
        else
        {
            special_char_count++;
        }
    }
    printf("Number of alphabets in the string : %d\n",alpha_count);
    printf("Number of digits in the string : %d\n",digit_count);
    printf("Number of special characters in the string : %d",special_char_count);
    return 0;
}
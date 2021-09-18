//2. Design a structure ‘student_record’ to store student details like name, SAP ID, 
//enrollment number, date of registration and data of birth. The element date of joining is 
//defined using another structure ‘date’ to store date details like day, month, and year. 
//Get data of ‘n’ students and then print the entered values.
#include<stdio.h>
struct date    //structure date to store the data of DOB, DOR and DOJ
{
    int day;
    int month;
    int year;
};

struct student_record   //structure student_record to store the details like name,Sap ID, enrollment number
{
    char name[60];
    int SapID;
    char enroll_num[20];
    struct date DOB,date_of_register,date_of_joining;   //nesting of the structure date in the structure student_record
};

int main()
{
    int n;
    printf("\nEnter the number of how many details of sudent you have to enter : ");
    scanf("%d",&n);
    struct student_record details[n];
    
    for(int i=0;i<n;i++)
    {
        printf("Enter the details of the student %d :\n",i+1);
        printf("Enter the name : ");          
        while(getchar()!='\n');
        fgets(details[i].name,60,stdin);
        printf("Enter the SAP ID : ");
        scanf("%d",&details[i].SapID);
        printf("Enter the Enrollment number : ");
        scanf("%s",details[i].enroll_num);
        
        printf("Enter the date of birth : \n");
        printf("Enter the day : ");
        scanf("%d",&details[i].DOB.day);
        printf("Enter the month : ");
        scanf("%d",&details[i].DOB.month);
        printf("Enter the year : ");
        scanf("%d",&details[i].DOB.year);
        
        printf("Enter the date of registeration : ");
        printf("\nEnter the day : ");
        scanf("%d",&details[i].date_of_register.day);
        printf("Enter the month :  ");
        scanf("%d",&details[i].date_of_register.month);
        printf("Enter the year : ");
        scanf("%d",&details[i].date_of_register.year);
        
        printf("Enter the date of joining : ");
        printf("\nEnter the day : ");
        scanf("%d",&details[i].date_of_joining.day);
        printf("Enter the month : ");
        scanf("%d",&details[i].date_of_joining.month);
        printf("Enter the year : ");
        scanf("%d",&details[i].date_of_joining.year);
    }
    printf("\n\t\tStudent Details : ");
    for(int j=0;j<n;j++)
    {
        printf("\n\nDetails of student %d : ",j+1);
        printf("\nName : %s",details[j].name);
        printf("Sap : %d",details[j].SapID);
        printf("\nEnrollment number : %s",details[j].enroll_num);
        printf("\nData of Birth : %d/%d/%d",details[j].DOB.day,details[j].DOB.month,details[j].DOB.year);
        printf("\nDate of Registration : %d/%d/%d",details[j].date_of_register.day,details[j].date_of_register.month,details[j].date_of_register.year);
        
        printf("\nData of Joining : %d/%d/%d",details[j].date_of_joining.day,details[j].date_of_joining.month,details[j].date_of_joining.year);
    }
    return 0;
}
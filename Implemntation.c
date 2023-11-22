#include "Header.h"
#include "string.h"


static int count=0;

void add_Student(std_info *s)
{

    printf("Add The Following information to Add Student\n");
    printf("Enter The Student Name :");
    string_scan(s[count].name,20);
    printf("Enter age: ");
    scanf("%d",&s[count].Age);
    printf("Enter Id: ");
    scanf("%d",&s[count].ID);
    printf("Enter Phone: ");
    string_scan(s[count].phone,12);
    count++;


}

void find_StudentbyID(std_info *s)
{
    int temp,flag=0;
    printf("Enter the ID of the Student you Want to Find \n");
    scanf("%d",&temp);
    for(int i=0; i<count; i++)
    {
        if(temp==s[i].ID)
        {
            printf("The student's details are\n");
            printf("The first name is %s\n",s[i].name);
            printf("The Age is %d\n",s[i].Age);
            printf("The ID is %d\n",s[i].ID);
            printf("phone Number is %s\n",s[i].phone);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("There is no Student with that name\n");
    }
}

void delete_StudentbyID(std_info *s)
{
    int temp;
    printf("Enter the ID of the Student you want to delete : ");
    scanf("%d",&temp);
    for(int i=0; i<count; i++)
    {
        if(temp==s[i].ID)
        {
            for(int k=i; k<count; k++)
            {
                s[k]=s[k+1];
            }
        }
    }
    printf("Student Details deleted successfully \n");

}

void Edit_Student(std_info *s)
{

    int temp;
    printf("Enter the ID of the Student you want to Edit : ");
    scanf("%d",&temp);
    for(int i=0; i<count; i++)
    {
        if(temp==s[i].ID)
        {
            printf("1-Name\n2-Age\n3-ID\n4-Phone\n");

            int c;
            scanf("%d",&c);
            switch(c)
            {
            case 1:
                printf("Enter the updated name : ");
                scanf("%s",s[i].name);
                break;
            case 2:
                printf("Enter the updated Age : ");
                scanf("%s",s[i].Age);
                break;
            case 3:
                printf("Enter the updated ID : ");
                scanf("%s",s[i].ID);
                break;

            case 4:
                printf("Enter the updated Phone : ");
                scanf("%s",s[i].phone);
                break;

            }



        }

    }
}

void print_School(std_info *s)
{

    for(int i=0 ; i<count; i++)
    {
        printf("name = %s\nAge=%d\nID=%d\nPhone=%s\n",s[i].name,s[i].Age,s[i].ID,s[i].phone);
        printf("====================================\n");
    }
}

void total_Student()
{
    printf("Total Student in the School is %d \n",count);
}

void call_Student(std_info *s)
{
    int temp;
    char flag=0;
    printf("Enter the ID of the Student you Want to Call : ");
    scanf("%d",&temp);
    for(int i=0;i<count; i++)
    {
        if(temp==s[i].ID)
        {
            printf("The Phone Number of that ID is %s\n",s[i].phone);
            printf("Calling...");
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("This ID is Not exist \n");
    }

}

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"


int main()
{
    std_info school[1000];
    int choice;
    while(1)
    {
        printf("\nWelcome In School Data base  System \n");
        printf("Enter What Want you to preform \n");
        printf("1- Add A New Student Details\n");
        printf("2- Search on a Student By ID and print it's Information\n");
        printf("3- Total Number of the student in School\n");
        printf("4- Delete the details of Student\n");
        printf("5- Edit the Student's Detials\n");
        printf("6- Calling the Student Entering it's name\n");
        printf("7- Print All The Student Details in School\n");
        printf("8- Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            add_Student(school);
            break;
        case 2:
            find_StudentbyID(school);
            break;
        case 3:
            total_Student();
            break;
        case 4:
            delete_StudentbyID(school);
            break;
        case 5:
            Edit_Student(school);
            break;
        case 6:
            call_Student(school);
            break;
        case 7:
            print_School(school);
            break;
        case 8:
            exit(0);
            break;
        default :
            exit(0);

        }

    }

    return 0;
}



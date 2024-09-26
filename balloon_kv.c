#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int print_choice()
{

    int choice; 

    restart: //this is a goto point

    printf("hello, what would you like to do?\n\n");
    printf("1.) Enter new contact and password\n\n");
    printf("2.) Search for contact and password\n\n");
    printf("3.) Delete or edit password and or contact information\n\n");
    printf("what is your choice? ");
    
    scanf("%d", &choice);
    
    if(choice >= 1 && choice <= 3)
    {
        return choice;
    }

    printf("try again: \n\n");
    goto restart;
}

void enter_info(char name[], char email[])
{
    //for loop here and index contact
    printf("\nWhat is the name: ");
    scanf(" %s", name);

    printf("\nwhat is the email: ");
    scanf(" %s", email);

}


int store_info(char** email, char** name, char email_varr[], char name_varr[], int max_entries)
{
    int counter1 = 0;
    //int counter = 0;

    char name_search[100];

    //int choice;
    //char email_varr[];
    //char name_varr[];

    //FILE* Storage= fopen("EmailStorage.txt", "w");
    //fprintf("%s", email_varr);
    //fprintf("%s", name_varr);
    
    
        if(counter1 >= max_entries)
        {
            printf("you have used all entries, please contact admin for more\n\n");
            exit(0);
        }

        email[counter1] = (char*)malloc(100 * sizeof(char));
        name[counter1] = (char*)malloc(100 * sizeof(char));

        if(email[counter1] == NULL || name[counter1] == NULL)
        {
            printf("memory allocation failed - contact support.");
            exit(0);
        }

        strcpy(email[counter1], email_varr);
        strcpy(name[counter1], name_varr);

        printf("is this info correct?\n\nNAME: %s\n\nEMAIL: %s\n\n", name[counter1], email[counter1]);
        counter1++;

        int user_answer;

        if(user_answer == 1)
        {
            return 1;
        }

        return 0;
        
}

void search_info(char name_search[])
{
    printf("enter the name of the person you want to find");
    scanf("%s", name_search);

}

void edit_info()
{
    printf(".");
}

int main()
{

    int max_entries = 100;
    char **email = (char**)malloc(max_entries* sizeof(char*));
    char **name = (char **)malloc(max_entries * sizeof(char*));
    char email_varr[100];
    char name_varr[100];
    int choice = 0;
    char name_search[100];



    if(email == NULL || name == NULL)
    {
        printf("memory allocation has failed - please contact support");
        exit(0);
    }

    int user_choice;

    user_choice = print_choice();

    switch(user_choice)
    {
    case 1:
        enter_info(name_varr, email_varr);
        store_info(email, name, email_varr, name_varr, max_entries);
        
        break;

    case 2:
        search_info(name_search);
        break;
    
    case 3:
        edit_info();

    default:
        printf("~~ERROR CODE: 1202200221202004 TERMINATING~~");
    
        break;
    }

    for(int i = 0; i < max_entries; i++)
    {
        if(email[i] != NULL)
        {
            free(email);
        }
        if(name[i] != NULL)
        {
            free(name);
        }
    }

    //free(email);
    //free(name);

    printf("%s", name[0]);
}
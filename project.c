#include<stdio.h>
#include<string.h>
#include <ctype.h>



int main () {

    /* char task[100][100];
    int taskCount= 0; */


    printf("\n\n");
    for ( int i = 0; i<20; i++ ) {
        if ( i == 10 ) {
            printf("Log in");
        }
        else {
            printf("-");
        }
    }
    printf("\n\n");

    printf("Enter Username: ");
    char username[20];
    gets(username);

    printf("Enter password: (maximum 8 char, must have one character and one digit and one uppercase letter)\n");

    int flag = -1;
    while ( flag != 0 ) {

        int aplha = 0;
        int digit = 0;
        int uppercase = 0;

        char pass[100];
        gets(pass);

        for ( int i = 0; i<9; i++ ) {
            if ( isalpha(pass[i]) && isupper(pass[i])) {
                aplha++;
                uppercase++;
            }
            else if ( isdigit(pass[i]) ) {
                digit++;
            }
        }

        if ( aplha > 0 && digit > 0 && uppercase > 0 && strlen(pass) >=8 ) {
            flag = 0;
            printf("\nUsername -> ");
            puts(username);

            printf("password -> ");
            for ( int i = 0; i<strlen(pass); i++ ) {
                printf("*");
            }

            printf("\n\nwrite y or Y to see your password\n");
            char ch;
            scanf("%c", &ch);
            if ( ch == 'Y' || ch == 'y' ) {
                printf("\nUsername -> ");
                puts(username);

                printf("password -> ");
                puts(pass);
            }
        }
        else {
            printf("failed to meet the criteria\n");
            flag = -1;
        }
    }


    // puts(pass);




    /* printf("\nTo-Do List Application:\n");
    printf("1. View all tasks\n");
    printf("2. Add a new task\n");
    printf("4. Mark task as completed\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");

    int choice = 0;
    while ( choice!=3 ) {
    scanf("%d", &choice);
    getchar();

    if ( choice == 1 ) {

        if ( taskCount == 0 ) {
            printf("No task added yet! Press 2 for adding task\n");
        }
        else {
            for ( int i = 0; i<taskCount; i++ ) {
                printf("%d. %s\n",i+1, task[i]);
            }
            printf("Successfully added %d task\n", taskCount);
            printf("to add task press 2\n");
            printf("4. Mark task as completed\n");

            printf("press 3 for exit\n");

        }
    }

    else if ( choice == 2 ) {
        printf("write a new task: ");
        char ch[100];
	    fgets(ch, 100, stdin);
        int length = strlen(ch);

        for ( int j = 0; j<length; j++ ) {
            task[taskCount][j] = ch[j];
        }
        task[taskCount][length] = '\0';
        printf("\nadded task -> %s\n\n", task[taskCount]);
        taskCount++;
        printf("to show list press 1\nto add task press 2\n");
        printf("4. Mark task as completed\n");
        printf("press 3 for exit\n");
    }

    else if ( choice == 4 ) {
        int completedTask;

        for ( int i = 0; i<taskCount; i++ ) {
            if ( completedTask-1 == i ) {
                printf("%d. %s (completed)\n",i+1, task[i]);
            }
            else{
                printf("%d. %s\n",i+1, task[i]);
            }
        }

        printf("\nWhich number you completed?");
        scanf("%d", &completedTask);

        for ( int i = 0; i<taskCount; i++ ) {
            if ( completedTask-1 == i ) {
                printf("%d. %s (completed)\n",i+1, task[i]);
            }
            else{
                printf("%d. %s\n",i+1, task[i]);
            }
        }

        printf("to add task press 2\n");
        printf("press 4 to Mark another task as completed\n");
    }


    } */ //while

    
   
   return 0;
}
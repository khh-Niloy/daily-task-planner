#include<stdio.h>
#include<string.h>
#include <ctype.h>

// global declaration
char task[100][100];
int taskCount= 0;
char recentCompletedTask[100];

char completedTaskList[100];
char deleteTaskNumber[100];




int totalTaskIdeleted = 0;


void viewTask(){

    if ( taskCount == 0 ) {
            printf("No task added yet! Press 2 for adding task\n");
        }
        else {

            printf("\n\n");
            for ( int i = 0; i<20; i++ ) {
                if ( i == 10 ) {
                    printf("All task list");
                }
                else {
                    printf("-");
                }
            }
            printf("\n\n");

            // printf("%d", totalTaskIdeleted);

            for ( int i = 0; i<taskCount; i++ ) {

                if ( completedTaskList[i] ==  1 ) {
                    printf("%d. %s(completed)\n",i+1, task[i]);
                }

                /* if ( strcmp(recentCompletedTask, task[i]) == 0 ) {
                    printf("%d. %s(completed)\n",i+1, task[i]);
                } */
                else {
                    printf("%d. %s\n",i+1, task[i]);
                }
                /* if ( deleteTaskNumber[i] == completedTaskList[i] ) {
                    completedTaskList[i] = 0;
                }
                if ( completedTaskList[i] == 1 ) {
                    printf("%d. %s(completed)\n",i+1, task[i]);
                }
                else {
                    printf("%d. %s\n",i+1, task[i]);
                } */
            }

            printf("\n");
            for ( int i = 0; i<20; i++ ) {
                printf("-");
            }
            printf("\n\n");

            printf("2. Add new task\n");
            printf("3. Mark task as completed\n");
            printf("4. delete task\n");
            printf("5. Exit\n\n");
        }
}


void addTask(){
    printf("write a new task: ");
    char ch[100];
	fgets(ch, 100, stdin);
    int length = strlen(ch);

    for ( int j = 0; j<length; j++ ) {
        task[taskCount][j] = ch[j];
    }
    task[taskCount][length] = '\0';
    printf("\nNewly added task -> %s\n\n", task[taskCount]);
    taskCount++;

    printf("1. Your current tasks\n");
    printf("2. Add new task\n");
    printf("3. Mark task as completed\n");
    printf("4. delete task\n");
    printf("5. Exit\n\n");
}


void markCompletedTask(){
    int completedTask;

    if ( taskCount == 0 ) {
        printf("No task added yet! Press 2 for adding task\n");
    }

    else{
        printf("\n\nEnter the task number to mark as completed:  ");
        scanf("%d", &completedTask);
        // completedTaskList[completedTask-1] = 1;
        strcpy(recentCompletedTask, task[completedTask-1]);

        printf("completed task: %s",recentCompletedTask);

        completedTaskList[completedTask-1] = 1;

        /* for ( int i = 0; i<taskCount; i++ ) {
            if ( completedTask == i+1 ) {
                printf("%d. %s (marked as completed)\n",i+1, task[i]);
            }
            else{
                printf("%d. %s\n",i+1, task[i]);
            }
        } */

        printf("\n\n\n");
        printf("1. Your current tasks\n");
        printf("2. Add new task\n");
        printf("3. Mark task as completed\n");
        printf("4. delete task\n");
        printf("5. Exit\n\n");
    }
}


void deleteTask(){

    if ( taskCount == 0 ) {
        printf("No task added yet! Press 2 for adding task\n");
    }

    else {
        printf("\n\n");
    int deleteTask;
    printf("which number you want to delete? ");
    scanf("%d", &deleteTask);

    // deleteTaskNumber[deleteTask] = 1;
    totalTaskIdeleted++;
    char recentDeleted[100];
    strcpy(recentDeleted, task[deleteTask-1]);

    for ( int i = deleteTask; i<taskCount; i++ ) {
        strcpy(task[i-1], task[i]);
    }
    printf("deleted task: %s",recentDeleted);
    taskCount--;

    if ( completedTaskList[deleteTask-1] ==  recentDeleted[deleteTask-1]) {
        completedTaskList[deleteTask-1] = 0;
    }
    /* for ( int i = 0; i<taskCount; i++ ) {
        printf("%d. %s\n",i+1, task[i]);
    } */

    printf("\n\n\n");
    printf("1. Your current tasks\n");
    printf("2. Add new task\n");
    printf("3. Mark task as completed\n");
    printf("4. delete task\n");
    printf("5. Exit\n\n");
    }
}


int main () {



    // username and pass
    /* printf("\n\n");
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

    printf("Enter password: (minimum 8 char, must have one character and one digit and one uppercase letter)\n\n");

    int flag = -1;
    while ( flag != 0 ) {

        int aplha = 0;
        int digit = 0;
        int uppercase = 0;

        char pass[100];
        gets(pass);

        for ( int i = 0; i<9; i++ ) {
            if ( isalpha(pass[i])) {
                aplha++;
            }
            if (isupper(pass[i])) {
                uppercase++;
            }
            if ( isdigit(pass[i]) ) {
                digit++;
            }
        }

        if ( aplha > 0 && digit > 0 && uppercase > 0 && strlen(pass) >=8 ) {
            flag = 0;

            printf("\n\n");
            for ( int i = 0; i<20; i++ ) {
                if ( i == 10 ) {
                    printf("You successfully created an account!");
                }
                else {
                    printf("-");
                }
            }

            printf("\nUsername -> ");
            puts(username);
        
            printf("password -> ");
            for ( int i = 0; i<strlen(pass); i++ ) {
                printf("*");
            }

            printf("\n");
            for ( int i = 0; i<(20+35); i++ ) {
                printf("-");
            }

            printf("\n\nwrite y or Y to see your password: ");
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
            if ( aplha==0 ) {
                printf("\nPlease add one letter\n\n");
            }
            if (digit==0) {
                printf("\nPlease add digit\n\n");
            }
            if (uppercase==0) {
                printf("\nPlease add one uppercase letter\n\n");
            }
            if (strlen(pass) < 8) {
                printf("\nminimum 8 letter!\n\n");
            }
            flag = -1;
        }
    } */



    printf("\nTo-Do List Application:\n");
    printf("Date: 23 Sept, 2024\n");
    printf("1. Your current tasks\n");
    printf("2. Add new task\n");
    printf("3. Mark task as completed\n");
    printf("4. delete task\n");
    printf("5. Exit\n\n");
    printf("Enter your choice: ");

    int choice = 0;
    while ( choice!=5 ) {
        scanf("%d", &choice);
        getchar();

        if ( choice == 1 ) {
            viewTask();
        }

        else if ( choice == 2 ) {
            addTask();
        }

        else if ( choice == 3 ) {
            markCompletedTask();
        }
        else if ( choice == 4 ) {
            deleteTask();
        }
    }

    
   
   return 0;
}
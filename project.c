#include<stdio.h>
#include<string.h>
#include <ctype.h>

    // global declaration
    char task[100][100];
    char completedTaskList[100];
    char deleteTaskNumber[100];
    int taskCount= 0;


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



            for ( int i = 0; i<taskCount-strlen(deleteTaskNumber); i++ ) {
                if ( deleteTaskNumber[i] == completedTaskList[i] ) {
                    completedTaskList[i] = 0;
                }
                if ( completedTaskList[i] == 1 ) {
                    printf("%d. %s(completed)\n",i+1, task[i]);
                }
                else {
                    printf("%d. %s\n",i+1, task[i]);
                }
            }

            printf("\n\n");
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
        completedTaskList[completedTask-1] = 1;

        for ( int i = 0; i<taskCount; i++ ) {
            if ( completedTask == i+1 ) {
                printf("%d. %s (marked as completed)\n",i+1, task[i]);
            }
            else{
                printf("%d. %s\n",i+1, task[i]);
            }
        }

        printf("\n\n\n");
        printf("1. Your current tasks\n");
        printf("2. Add new task\n");
        printf("3. Mark task as completed\n");
        printf("4. delete task\n");
        printf("5. Exit\n\n");
    }
}


void deleteTask(){
    printf("\n\n");
    int deleteTask;
    printf("which number you want to delete? ");
    scanf("%d", &deleteTask);

    deleteTaskNumber[deleteTask-1] = 1;

    for ( int i = deleteTask; i<taskCount; i++ ) {
        strcpy(task[i-1], task[i]);
    }
    taskCount--;

    for ( int i = 0; i<taskCount; i++ ) {
        printf("%d. %s\n",i+1, task[i]);
    }

    printf("\n\n\n");
    printf("1. Your current tasks\n");
    printf("2. Add new task\n");
    printf("3. Mark task as completed\n");
    printf("4. delete task\n");
    printf("5. Exit\n\n");
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
    } */



    printf("\nTo-Do List Application:\n");
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



    } //while

    
   
   return 0;
}
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <conio.h>


// global declaration
 char task[100][100];
int taskCount= 0;
char recentCompletedTask[100];

char completedTaskList[100];
char deleteTaskNumber[100];

char listedCompletedTask[100][100];
int listedCompletedTaskCounter = 0;

char listedDeletedTask[100][100];
int listedDeletedTaskCounter = 0;

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

            for ( int i = 0; i<taskCount; i++ ) {

                if ( completedTaskList[i] ==  1 ) {
                    printf("\xE2\x9C\x85 %d. %s \n", i + 1, task[i]);
                }
                else {
                    printf("%d. %s\n",i+1, task[i]);
                }
            }

            printf("\n");
            for ( int i = 0; i<20; i++ ) {
                printf("-");
            }
            printf("\n\n");

            printf("2. Add new task\n");
            printf("3. Mark task as completed\n");
            printf("4. delete task\n");
            printf("5. All completed task\n");
            printf("6. All deleted task\n");
            printf("7. Exit\n\n");
            printf("Enter your choice: ");
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
    printf("5. All completed task\n");
    printf("6. All deleted task\n");
    printf("7. Exit\n\n");
    printf("Enter your choice: ");
}


void markCompletedTask(){
    int completedTask;
    if ( taskCount == 0 ) {
        printf("No task added yet! Press 2 for adding task\n");
    }
    else{
        listedCompletedTaskCounter++;
        printf("\n\nEnter the task number to mark as completed:  ");
        scanf("%d", &completedTask);

        strcpy(recentCompletedTask, task[completedTask-1]);
        printf("completed task: %s",recentCompletedTask);
        completedTaskList[completedTask-1] = 1;

        strcpy(listedCompletedTask[listedCompletedTaskCounter-1], recentCompletedTask);

        printf("\n\n\n");
        printf("\n\n\n");
        printf("1. Your current tasks\n");
        printf("2. Add new task\n");
        printf("3. Mark task as completed\n");
        printf("4. delete task\n");
        printf("5. All completed task\n");
        printf("6. All deleted task\n");
        printf("7. Exit\n\n");
        printf("Enter your choice: ");
    }
}


void deleteTask(){

    if ( taskCount == 0 ) {
        printf("No task added yet! Press 2 for adding task\n");
    }
    else {
        listedDeletedTaskCounter++;
        printf("\n\n");
        int deleteTask;
        printf("which number you want to delete? ");
        scanf("%d", &deleteTask);

        totalTaskIdeleted++;
        char recentDeleted[100];
        strcpy(recentDeleted, task[deleteTask-1]);

        for ( int i = deleteTask; i<taskCount; i++ ) {
            strcpy(task[i-1], task[i]);
        }
        printf("\n\n\u274C deleted task: %s",recentDeleted);

        taskCount--;
        completedTaskList[deleteTask-1] = 0;

        strcpy(listedDeletedTask[listedDeletedTaskCounter-1], recentDeleted);

        printf("\n\n\n");
        printf("1. Your current tasks\n");
        printf("2. Add new task\n");
        printf("3. Mark task as completed\n");
        printf("4. delete task\n");
        printf("5. All completed task\n");
        printf("6. All deleted task\n");
        printf("7. Exit\n\n");
        printf("Enter your choice: ");
        
    }
}


void listOfAllCompletedTask(){
    if ( taskCount == 0 ) {
        printf("No task added yet! Press 2 for adding task\n");
    }
    else if (listedCompletedTaskCounter == 0) {
        printf("No task completed yet! Press 3 for adding completed task\n");
    }
    else{
        printf("\n\n");
        for ( int i = 0; i<10; i++ ) {
            if ( i == 5 ) {
                printf("All completed task list");
            }
            else {
                printf("-");
            }
        }
        printf("\n\n");


        for ( int i = 0; i<listedCompletedTaskCounter; i++ ) {
            printf("%d. %s", i+1, listedCompletedTask[i]);
        }


        printf("\n");
        for ( int i = 0; i<32; i++ ) {
            printf("-");
        }
        printf("\n\n");

        printf("1. Your current tasks\n");
        printf("2. Add new task\n");
        printf("3. Mark task as completed\n");
        printf("4. delete task\n");
        printf("5. All completed task\n");
        printf("6. All deleted task\n");
        printf("7. Exit\n\n");
        printf("Enter your choice: ");
    }
}


void listOfAllDeletedTask(){
    if ( taskCount == 0 ) {
        printf("No task added yet! Press 2 for adding task\n");
    }
    else if (listedDeletedTaskCounter == 0) {
        printf("No task deleted yet! Press 4 for adding deleted task\n");
    }
    else{
        printf("\n\n");
        for ( int i = 0; i<10; i++ ) {
            if ( i == 5 ) {
                printf("All deleted task list");
            }
            else {
                printf("-");
            }
        }
        printf("\n\n");


        for ( int i = 0; i<listedDeletedTaskCounter; i++ ) {
            printf("%d. %s", i+1, listedDeletedTask[i]);
        }


        printf("\n");
        for ( int i = 0; i<32; i++ ) {
            printf("-");
        }
        printf("\n\n");

        printf("1. Your current tasks\n");
        printf("2. Add new task\n");
        printf("3. Mark task as completed\n");
        printf("4. delete task\n");
        printf("5. All completed task\n");
        printf("6. All deleted task\n");
        printf("7. Exit\n\n");
        printf("Enter your choice: ");
    }
}
 

void search(){
    printf("\nPlease enter the task you're looking for: ");
    char SearchCh[100];
	fgets(SearchCh, 100, stdin);

    char storeSearchedTask[100][100];
    printf("\n");
    SearchCh[strcspn(SearchCh, "\n")] = '\0';

    int found = 0;
    for ( int i = 0; i<taskCount; i++ ) {
        if(strstr(task[i], SearchCh) != NULL){
            strcpy(storeSearchedTask[i], task[i]);
            found++;
        }
    }
    printf("\n");
    for ( int i = 0; i<found; i++ ) {
        printf("%d. %s\n", i+1,storeSearchedTask[i]);
    }

    for (int i = 0; i < found; i++) {
        storeSearchedTask[i][0] = '\0';
    }

    if ( found == 0 ) {
        printf("No matching task found.Please press 8 to try again.\n\n");
    }
    else{
        printf("press 8 to try again: ");
    }
}


int main () {

    // username and pass
    /* printf("\n\n");
    for ( int i = 0; i<20; i++ ) {
        if ( i == 10 ) {
            printf("Registration Form");
        }
        else {
            printf("-");
        }
    }
    printf("\n\n");

    printf("Enter your email: ");

    char username[20];
    int presentAtChar = 0;
    int emailCheckMessageFlag = 0;
    int flag2 = -1;
    
    while (flag2 != 0){
        gets(username);

        for ( int i = 0; i<strlen(username); i++ ) {
            if (username[i] == '@') {
                presentAtChar++;
                flag2 = 0;
            }
        }

        if (presentAtChar == 0) {
            if (emailCheckMessageFlag == 0) {
                printf("Please enter a valid email address.\n");
            }
            emailCheckMessageFlag++;
        }
    }


    printf("\n\nPassword requirements: Minimum 8 characters, including one letter, one digit, and one uppercase letter\n\n");
    printf("Enter Password:\n");

    int flag = -1;
    int passCheckMessageFlag = 0;
    while ( flag != 0 ) {

        int aplha = 0;
        int digit = 0;
        int uppercase = 0;

        char pass[100];
        char passCh;
        int i = 0;
        while(1){
            passCh = _getch();

            if (passCh == '\r') {
                pass[i] = '\0';
                break;
            }
            else if (passCh == '\b' && i > 0) {
                printf("\b \b");
                i--;
            }
            else if (passCh != '\b'){
                pass[i] = passCh;
                printf("*");
                i++;
            }
        }

        printf("\n");

        for ( int i = 0; i<strlen(pass); i++ ) {
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

            printf("\nEmail -> ");
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
            if (aplha==0 || digit==0 || uppercase==0 || strlen(pass) < 8) {
                passCheckMessageFlag++;
                if (passCheckMessageFlag == 1) {
                    printf("\nPlease meet the requirements\n");
                }
            }
            flag = -1;
        }
    }

 */

     printf("\nTo-Do List Application:\n");
    printf("Date: 23 Sept, 2024\n");
    printf("1. Your current tasks\n");
    printf("2. Add new task\n");
    printf("3. Mark task as completed\n");
    printf("4. delete task\n");
    printf("5. All completed task\n");
    printf("6. All deleted task\n");
    printf("Search\n");
    printf("7. Exit\n\n");
    printf("Enter your choice: "); 

     int choice = 0;
    while ( choice!=7 ) {
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
        else if ( choice == 5 ) {
            listOfAllCompletedTask();
        }
        else if ( choice == 6 ) {
            listOfAllDeletedTask();
        }
        else if ( choice == 8 ) {
            search();
        }
    } 

   return 0;
}
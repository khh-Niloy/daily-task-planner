#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>

// global declaration
char task[100][100];
int taskCount= 0;

char recentCompletedTask[100];
char completedTaskList[100];
char listedCompletedTask[100][100];
int listedCompletedTaskCounter = 0;

char listedDeletedTask[100][100];
int listedDeletedTaskCounter = 0;
int totalTaskIdeleted = 0;

char* showDate(){
    time_t current_time;
    struct tm *time_info;

    time(&current_time);
    time_info = localtime(&current_time);
    char *date = asctime(time_info);
    date[strcspn(date, "\n")] = '\0';

    return date;
}

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
                    printf("(Done) %d. %s \n", i + 1, task[i]);
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

    strcat(task[taskCount], " (");
    strcat(task[taskCount], showDate());
    strcat(task[taskCount], ") ");

    printf("\nNewly added task -> %s\n\n", task[taskCount]);
    taskCount++;
    printf("Enter your choice: ");
}

void search(){
    if ( taskCount == 0 ) {
        printf("No task added yet! Press 2 for adding task\n");
    }
    else{
    printf("\nPlease enter the task you're looking for: ");
    char SearchCh[100];
    fgets(SearchCh, 100, stdin);

    char storeSearchedTask[100][100];
    printf("\n");
    SearchCh[strcspn(SearchCh, "\n")] = '\0';

    int found = 0;
    for ( int i = 0; i<taskCount; i++ ) {
        if(strstr(task[i], SearchCh) != NULL){
            strcpy(storeSearchedTask[found], task[i]);
            found++;
        }
    }
    printf("\n");
    if ( found == 0 ) {
        printf("No matching task found.Please press 3 to try again.\n\n");
    }
    else{
        printf("Found %d matching task(s)\n", found);
        for ( int i = 0; i<found; i++ ) {
            printf("%d. %s\n", i+1,storeSearchedTask[i]);
        }
        printf("\nWant to search again? Press 3\n");
    }
    }

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
        printf("completed task: %s\n\n",recentCompletedTask);
        completedTaskList[completedTask-1] = 1;

        strcpy(listedCompletedTask[listedCompletedTaskCounter-1], recentCompletedTask);

        printf("Press 4 to mark again or press 1 to see the list : ");

    }
}



void listOfAllCompletedTask(){
    if ( taskCount == 0 ) {
        printf("No task added yet! Press 2 for adding task\n");
    }
    else if (listedCompletedTaskCounter == 0) {
        printf("No task completed yet! Press 4 for adding completed task\n");
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
            printf("%d. %s\n", i+1, listedCompletedTask[i]);
        }

        printf("\n");
        for ( int i = 0; i<32; i++ ) {
            printf("-");
        }
        printf("\n\n");
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
        printf("\n\n deleted task: %s",recentDeleted);

        taskCount--;
        completedTaskList[deleteTask-1] = 0;

        strcpy(listedDeletedTask[listedDeletedTaskCounter-1], recentDeleted);

        printf("\n\n\n");
        printf("you can see the deleted list task by pressing 7.\n");
        printf("or press 6 to delete again, press 1 to see the updated list and 2 to add the list : ");

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
        printf("press 6 to delete or 2 to add to the list : ");
    }
}





int main () {

    // username and pass
     printf("\n\n");
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
                    printf("Successfully, created an account!");
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

            printf("\n\npress y to see password or press n: ");
            char toSeePass;
            scanf("%c", &toSeePass);
            if ( toSeePass == 'y' ) {
                printf("\nUsername -> ");
                puts(username);

                printf("password -> ");
                puts(pass);
            }

        }

        else {
            if (aplha==0 || digit==0 || uppercase==0 || strlen(pass) < 6) {
                passCheckMessageFlag++;
                if (passCheckMessageFlag == 1) {
                    printf("\nPlease meet the requirements\n");
                }
            }
            flag = -1;
        }
    }




    printf("\nTo-Do List Application:\n");
    printf("Date: ");
    printf(showDate());

    printf("\n");
    printf("1. Your current tasks\n");
    printf("2. Add new task\n");
    printf("3. Search\n");
    printf("4. Mark task as completed\n");
    printf("5. All completed task\n");
    printf("6. Delete a task\n");
    printf("7. All deleted task\n");
    printf("8. Exit\n\n");
    printf("Enter your choice: ");

    int choice = 0;
    while ( choice!=8 ) {
        scanf("%d", &choice);
        getchar();

        if ( choice == 1 ) {
            viewTask();
        }

        else if ( choice == 2 ) {
            addTask();
        }
        else if ( choice == 3 ) {
            search();
        }
        else if ( choice == 4 ) {
            markCompletedTask();
        }
        else if ( choice == 5 ) {
            listOfAllCompletedTask();
        }
        else if ( choice == 6 ) {
            deleteTask();
        }
        else if ( choice == 7 ) {
            listOfAllDeletedTask();
        }
    }

   return 0;
}


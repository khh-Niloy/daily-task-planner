#include<stdio.h>
#include<string.h>

int main () {

    char task[100][100];
    int taskCount= 0;

    printf("\nTo-Do List Application:\n");
    printf("1. View all tasks\n");
    printf("2. Add a new task\n");
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
        printf("press 3 for exit\n");
    }
    }
    
   
   return 0;
}
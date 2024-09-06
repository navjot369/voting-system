#include <stdio.h>
#include <stdlib.h>
#include "../include/takeVote.h"

void singleVote(int* data, int total, char options[][100], int* turn) {
    int choice;
    while(1) {
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        if(choice < 1 || choice > total) {
            printf(" Choose a valid options (1 to %d). \n ", total);
        } else {
            break;
        }
    }
    while(getchar() != '\n');

    printf("Your voted for option - %d. %s \n", choice, options[choice-1]);
    char ch;
    while(1) {
        printf("Press Enter to confirm and N before Enter to cancel: ");
        ch = getchar();
        if(ch == '\n') {
            *(data+choice-1) += 1;
            (*turn)++;
            break;
        }else if(ch == 'N') {
            break;
        }else{
            printf(" Choose valid option - Enter/N before Enter \n");
        }
    }
}

void multiVote(int* data, int total, char options[][100], int* turn) {
    char choice;
    int storeChoices[total];

    for(int i = 0;i < total; i++) storeChoices[i] = 0;
    printf("** Choose multiple times, leave black when finished. \n");
    while(1) {
        printf("Enter your Choice: ");
        choice = getchar();
        if(choice == '\n') {
            break;
        }
        while(getchar() != '\n');
        choice -= '0';

        if(choice < 1 || choice > total ) {
            printf("     Choose a valid number (1 to %d).\n", total);
        } else {
            if(storeChoices[choice-1] == 0) {
                storeChoices[choice-1] += 1;
            }
            else {
                printf("  This options is already taken..! \n");
            }
        }
    }

    printf("Your voted for option(s) - \n");
    for(int i = 0; i < total; i++) {
        if(storeChoices[i] == 1) {
            printf("     %d. %s \n", i+1, options[i]);
        }
    }

    char ch;
    while(1) {
        printf("Press Enter to confirm and N before Enter to cancel: ");
        ch = getchar();
        if(ch == '\n') {
            for(int i = 0; i < total; i++) {
                if(storeChoices[i] == 1) {
                    *(data+i) += 1;
                }
            }
            (*turn)++;
            break;
        }else if(ch == 'N') {
            break;
        }else{
            printf(" Choose valid option - Enter/N before Enter \n");
        }
    }
}

int nextVote() {
    system("clear");
    printf("       Your vote have been casted. \n");
    printf("  Press Enter to cast next Vote. Press any other key before enter to end voting. \n");
    char ch = getchar();
    if(ch == '\n') {
        return 1;
    }
    else{
        return 0;
    }
}

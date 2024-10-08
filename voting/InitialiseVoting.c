#include <stdio.h>
#include <string.h>
#include "../include/printOptions.h"
#include "../include/takeVote.h"
#include "../include/InitialiseVoting.h"
#include "../include/AnonymousVoting.h"
#include "../include/OpenVoting.h"

void startVoting() {
    char title[200];
    int numOptions;

    // Title and number of options required input
    printf("Enter title: ");
    fgets(title, 200, stdin);
    size_t len = strlen(title);
    if(title[len-1] == '\n') {
        title[len-1] = '\0';
    }
    while(1) {
        printf("Enter number of options: ");
        scanf("%d", &numOptions);
        if(numOptions <= 0) {
            printf("Not a valid response...! \n");
        }else{
            break;
        }
        printf("%d", numOptions);
    }

    while(getchar() != '\n');

    // Input of all the choices
    char options[numOptions][100];
    for(int i = 0; i < numOptions; i++) {
        printf("Enter options %d: ", i+1);
        fgets(options[i], 200, stdin);
        size_t len = strlen(options[i]);
        if(options[i][len-1] == '\n') {
            options[i][len-1] = '\0';
        }
    }

    //Is multiple options allowed
    char isMulti = 'O';
    void (*InputFunc)(int*, int, char[][100], int*);
    while(1) {
        printf("Allow Multiple options (Y/N)?  ");
        scanf("%c", &isMulti);
        while(getchar() != '\n');
        if(isMulti == 'N'){
            InputFunc = singleVote;
            break;
        }
        else if(isMulti == 'Y') {
            InputFunc = multiVote;
            break;
        }else{
            printf("Choose 'Y' for Yes and 'N' for No..!\n");
        }
    }

    //Is voting Anonymous
    char isAnonymous = 'O';
    while(1) {
        printf("Do you want to keep it anonymous (Y/N)?  ");
        scanf("%c", &isAnonymous);
        while(getchar() != '\n');
        if(isAnonymous == 'N' || isAnonymous == 'Y') {
            break;
        }else{
            printf("Choose 'Y' for Yes and 'N' for No..!\n");
        }
    }

    //Show real time stats
    char showReal = 'O';
    // Pointer to function to pass depending on whether to print real time stats or not
    void (*showOptionsFunc)(char[][100], char[], int, int*);
    while(1) {
        printf("Do you want to show real time count (Y/N)?  ");
        scanf("%c", &showReal);
        while(getchar() != '\n');
        if(showReal == 'Y') {
            showOptionsFunc = printOptionsWC; // print options with count
            break;
        } else if(showReal == 'N') {
            showOptionsFunc = printOptions;
            break;
        }else{
            printf("Choose 'Y' for Yes and 'N' for No..!\n");
        }
    }

    if(isAnonymous == 'Y') {
        startAnonymousVoting(title, options, numOptions, showOptionsFunc, InputFunc);
    }else{
        startOpenVoting(title, options, numOptions, showOptionsFunc, InputFunc);
    }
}

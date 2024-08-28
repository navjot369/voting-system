#include <stdio.h>


int main() {
    printf("WELCOME...!! Press enter to start Voting.");
    getchar();

    char title[200];
    int numOptions;

    // Title and number of options required input
    printf("\n");
    printf("Enter title: ");
    fgets(title, 200, stdin);
    while(1) {
        printf("Enter number of options: ");
        scanf("%d", &numOptions);
        if(numOptions <= 0) {
            printf("Not a valid response...! \n");
        }else{
            break;
        }
    }

    while(getchar() != '\n');

    // Input of all the choices
    char options[numOptions][100];
    for(int i = 0; i < numOptions; i++) {
        printf("Enter options %d: ", i+1);
        fgets(options[i], 200, stdin);
    }

    //Is multiple options allowed
    char isMulti = 'O';
    while(1) {
        printf("Allow Multiple options (Y/N)?  ");
        scanf("%c", &isMulti);
        while(getchar() != '\n');
        if(isMulti == 'N' || isMulti == 'Y') {
            break;
        }else{
            printf("Choose 'Y' for Yes and 'N' for No..!\n");
        }
    }

    //Is voting Anonymous
    char isAnonymous = 'N';
    while(1) {
        printf("Allow Multiple options (Y/N)?  ");
        scanf("%c", &isAnonymous);
        while(getchar() != '\n');
        if(isAnonymous == 'N' || isAnonymous == 'Y') {
            break;
        }else{
            printf("Choose 'Y' for Yes and 'N' for No..!\n");
        }
    }

    startVoting(title, options, numOptions, isMulti, isAnonymous);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "../include/takeVote.h"
#include "../include/AnonymousVoting.h"
#include "../include/getResult.h"
#include "../include/graphs.h"

void startAnonymousVoting(char title[200], char options[][100], int total,
 void (*showOptionsFunc)(char[][100], char[], int, int*),
 void (*InputFunc)(int*, int, char[][100], int*)) {

    int result[total];
    for(int i = 0; i < total; i++) result[i] = 0;

    int turn = 0;
    int cont = 1;

    system("clear");
    printf("Ready...! Press Enter to start voting");
    while(getchar() != '\n');

    while(cont == 1) {
        showOptionsFunc(options, title, total, result);
        InputFunc(result, total, options, &turn);
        if(nextVote()); else break;
    }

    system("clear");
    printf("Total number of votes casted - %d\n", turn);
    getResult(result, total, options);

    printf("\nInfographics available: \n");
    printf("1. Rank Wise List Table\n");
    printf("2. Bar showing ratio for every option\n");
    printf("3. Horizontal Bar Graph\n");
    printf("4. None\n");

    int chc;
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &chc);
        while(getchar() != '\n');
        if(chc < 1 || chc > 4) {
            printf("     Not a valid choice...!");
            continue;
        }
        if(chc == 4) break;
        switch (chc) {
            case 1:
            printRankWise(result, total, options);
            break;
            case 2:
            RatioLine(result, total, options);
            break;
            case 3:
            HorizontalBar(result, total, options);
            break;
            default:
            printf("    Not a valid choice...!");
            break;
        }
    }
    printf("  Voting END....! \n");
}

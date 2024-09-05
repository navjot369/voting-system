#include <stdio.h>
#include <stdlib.h>
#include "../include/takeVote.h"
#include "../include/AnonymousVoting.h"

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

    for(int i = 0; i < total; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

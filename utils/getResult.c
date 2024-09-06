#include <stdio.h>
#include <string.h>
#include "../include/getResult.h"

void printWinner(int ind, char option[100]) {
    int len = strlen(option) + 7;

    char border[101];
    for(int i = 0 ;i < 100; i++) border[i] = '-';
    border[100] = '\0';

    printf("      +%.*s+\n", len, border);
    printf("      |  %d. %s  |\n", ind, option);
    printf("      +%.*s+\n", len, border);

}


void getResult(int res[], int total, char options[][100]) {
    int winner = 0;
    int isTie = 0;
    for(int i = 0; i < total; i++) {
        if(res[i] > winner) {
            winner = res[i];
            isTie = 0;
        }
        if(res[i] == winner) {
            isTie++;
        }
    }

    if(winner == 0) {
        printf("No option get any vote...! :(");
        return;
    }

    if(isTie > 1) {
        printf("Seems like we get no single winner. :| \n");
        printf("Winners are: \n");
    }else{
        printf("Winner is: \n");
    }

    for(int i = 0; i < total; i++) {
        if(res[i] == winner) {
            printWinner(i+1, options[i]);
        }
    }
}

void printRankWise(int res[], int total, char options[][100]) {
    int winner = 0;
    for(int i = 0; i < total; i++) {
        if(res[i] > winner) {
            winner = res[i];
        }
    }

    if(winner == 0) {
        printf("No option get any vote...! :(");
        return;
    }

    int rank = 1;
    int count = 0;
    int isThisRank = 0;
    printf("| Rank | Count | Option \n");
    while(count < total) {
        for(int i = 0; i < total; i++) {
            if(res[i] == winner) {
                isThisRank = 1;
                printf("|%3d   |%4d   | %s \n", rank, res[i], options[i]);
                count++;
            }
        }
        if(isThisRank > 0)rank++;
        isThisRank = 0;
        winner--;
    }
}

// int main() {
//     printWinner(1, "Yes we did it");
// }

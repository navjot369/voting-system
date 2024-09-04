#include <stdio.h>
#include "../include/takeVote.h"
#include "../include/AnonymousVoting.h"

void startAnonymousVoting(char title[200], char options[][100], int total,
 void (*showOptionsFunc)(char[][100], char[], int, int*),
 void (*InputFunc)(int*, int, char[][100])) {

    int result[total];
    for(int i = 0; i < total; i++) result[i] = 0;

    int turns = 0;
    int cont = 1;

    while(cont == 1) {
        showOptionsFunc(options, title, total, result);
        InputFunc(result, total, options);
        if(nextVote()); else break;
    }
}

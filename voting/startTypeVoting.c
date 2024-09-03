#include <stdio.h>
#include "startTypeVoting.h"

void startAnonymousVoting(char title[200], char options[][100], int total,
 void (*showOptionsFunc)(char[][200], char[], int, int*),
 void (*InputFunc)(int*, int, char[][200])) {
    int result[total];
    int turns = 0;
    int cont = 1;

    while(cont == 1) {
        showOptionsFunc(options, title, total, result);
        InputFunc(result, total, options);
        cont = nextVote();
    }
}

void startOpenVoting() {
    char location[50];
    printf("Enter records file location: ");
    fgets(location, 50, stdin);

    FILE *file;
    file = fopen(location, "r");

    if(file == NULL) {
        printf("File not found...!!");
    }
}

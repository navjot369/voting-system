#include <stdio.h>
#include "../include/OpenVoting.h"

void startOpenVoting(char title[200], char options[][100], int total,
 void (*showOptionsFunc)(char[][100], char[], int, int*),
 void (*InputFunc)(int*, int, char[][100], int*)) {

    char location[50];
    printf("Enter records file location: ");
    fgets(location, 50, stdin);

    FILE *file;
    file = fopen(location, "r");

    if(file == NULL) {
        printf("File not found...!!");
    }
}

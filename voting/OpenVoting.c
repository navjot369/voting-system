#include <stdio.h>
#include <string.h>
#include "../include/OpenVoting.h"

void startOpenVoting(char title[200], char options[][100], int total,
 void (*showOptionsFunc)(char[][100], char[], int, int*),
 void (*InputFunc)(int*, int, char[][100], int*)) {

    FILE *file;
    file = fopen("./../votersRecord/data.txt", "r");

    if(file == NULL) {
        printf("File not found...!!");
        return;
    }else{
        printf("File opened");
    }
}

int main() {
    FILE *file;
    file = fopen("./../votersRecord/data.txt", "r");

    if(file == NULL) {
        printf("File not found...!!");
    }else{
        printf("File opened");
    }
}

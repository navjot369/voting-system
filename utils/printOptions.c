#include <stdio.h>
#include <stdlib.h>
#include "../include/printOptions.h"



void printOptionsWC(char options[][100], char title[], int total, int* curr) {
    system("clear");
    // printf( "\e[2J" );
    printf(" (Count)   %s\n", title);
    for(int i  = 0 ;i < total; i++) {
        printf("%5d      %d. %s\n", *(curr+i), i+1, options[i]);
    }
}

void printOptions(char options[][100], char title[], int total, int* curr) {
    system("clear");
    printf("   %s \n", title);
    for(int i  =0 ;i < total; i++) {
        printf("%d. %s \n", i+1, options[i]);
    }
    printf("\n");
}


// int main() {
//     char title[] = "what do u want???";
//     char options[3][200] = {"first options", "second one", "third options"};
//     int total = 3;
//     int curr[] = {2,3, 4};

//     printOptions(options, title, total, curr);
//     printOptionsWC(options, title, total, curr);
// }

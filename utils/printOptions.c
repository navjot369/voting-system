#include <stdio.h>
#include <stdlib.h>
#include "../include/printOptions.h"

int main() {
    nextVote(;printOptions.h"

void printOptionsWC(char options[][100], char title[], int total, int* curr) {
    system("clear");
    printf("   %-40s (Count) \n", title);
    for(int i  = 0 ;i < total; i++) {
        printf("%d. %-40s %4d\n", i+1, options[i], *(curr+i));
    }
    printf("\n");
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

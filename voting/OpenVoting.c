#include <stdio.h>
#include <string.h>
#include "../include/takeVote.h"
#include "../include/clearScreen.h"
#include "../include/getResult.h"
#include "../include/graphs.h"
#include "../include/OpenVoting.h"

struct student{
    long int id;
    char name[20];
    int year;
    int isHost;
};

typedef struct student std;

int bSearch(std data[], int s, int e, long int id) {
    if(s > e) {
        return -1;
    }

    int mid = (s+e)/2;
    if(data[mid].id == id) {
        return mid;
    }
    if(data[mid].id > id) {
        return bSearch(data, s, mid-1, id);
    }
    return bSearch(data, mid+1, e, id);
}

void startOpenVoting(char title[200], char options[][100], int total,
 void (*showOptionsFunc)(char[][100], char[], int, int*),
 void (*InputFunc)(int*, int, char[][100], int*)) {

    FILE *file;
    file = fopen("./../votersRecord/data/data.txt", "rb");

    if(file == NULL) {
        perror("Data not found...!!");
        return;
    }

    int size;
    fread(&size, sizeof(size), 1, file);

    std data[size];
    for(int i = 0; i < size; i++ ){
        fread(&data[i], sizeof(std), 1, file);
    }

    int result[size][total];
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < total; j++) {
            result[i][j] = -1;
        }
    }

    int mainResult[total];
    for(int i = 0; i < total; i++) mainResult[i] = 0;
    int turn = 0;
    int cont = 1;
    long int id;
    int ind;
    int voteCasted = 0;

    clearScreen();
    printf("Ready...! Press Enter to start voting");
    while(getchar() != '\n');

    while(cont == 1) {
        printf("Enter your Id: ");
        scanf("%ld", &id);
        while(getchar() != '\n');

        ind = bSearch(data, 0, size-1, id);
        if(ind == -1) {
            printf("Invalid Id...!\n");
            continue;
        }
        if(result[ind][0] == -1) {
            printf("You have already casted vote...!\n");
            continue;
        }
        for(int i = 0; i <total; i++) {
            result[ind][i] = 0;
        }
        printf("Welcome...! %s\n", data[ind].name);

        showOptionsFunc(options, title, total, mainResult);
        InputFunc(result[ind], total, options, &turn);

        voteCasted = 0;
        for(int i = 0; i < total; i++) {
            if(result[ind][i] > 0) voteCasted = 1;
            mainResult[i] += result[ind][i];
        }
        if(voteCasted == 0) {
            for(int i = 0; i < total; i++) {
                result[ind][i] = -1;
            }
        }
        if(nextVote()); else break;
    }

    clearScreen();
    printf("Total number of votes casted - %d\n", turn);
    getResult(mainResult, total, options);

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
            printRankWise(mainResult, total, options);
            break;
            case 2:
            RatioLine(mainResult, total, options);
            break;
            case 3:
            HorizontalBar(mainResult, total, options);
            break;
            default:
            printf("    Not a valid choice...!");
            break;
        }
    }
    printf("  Voting END....! \n");
    fclose(file);
}

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "./../include/handleDB.h"

void handleDB() {
    int option;
    DIR *dir;
    struct dirent *curr;
    int size = 1;
    printf("Choose the database to work upon: \n");
    dir = opendir("./data");
    char temp[20];
    int len;
    if(dir) {
        curr = readdir(dir);
        curr = readdir(dir);
        while((curr = readdir(dir)) != NULL) {
            strcpy(temp, curr->d_name);
            len = strlen(temp);
            temp[len-4] = '\0';
            printf("%d. %s\n", size, temp);
            size++;
        }
    }else{
        perror("Error accessing the Database...\n");
    }

    return;
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &option);
        while(getchar() != '\n');
        if(option > 0 && option < 4) {
            break;
        }
        else{
            printf("Not a valid choice...!\n");
        }
    }
    char path[50];
    switch(option) {
        case 1:
        strcpy(path, "g1.txt");
        break;
        case 2:
        strcpy(path, "g2.txt");
        break;
        case 3:
        strcpy(path, "g4.txt");
        break;
    }

    printf("Chooose operation you want to do: \n");
    printf("1. Print records\n2. Add new entry\n3. Update record\n4. Delete record\n5. Exit");
    int operation;
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &operation);
        while(getchar() != '\n');
        if(operation > 0 && operation < 6) {
            switch(operation) {
                case 1:
                // print record
                break;
                case 2:
                // add new entry
                break;
                case 3:
                // update record
                break;
                case 4:
                // delete record
                break;
                case 5:
                return;
            }
        } else {
            printf("Not a valid options...!\n");
        }
    }

}

void addRecord() {
}



int main() {

}

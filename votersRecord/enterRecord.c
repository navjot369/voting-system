#include <stdio.h>
#include <string.h>

struct student{
    long int id;
    char name[20];
    int year;
    int isHost;
};


typedef struct student std;

void writeData() {
    FILE* file;
    file = fopen("./votersRecord/data/data.txt", "wb");

    if(file == NULL) {
        perror("Error opening file...!");
        return;
    }

    int size;
    printf("Enter number of student records to add: ");
    scanf("%d", &size);
    fwrite(&size, sizeof(size), 1, file);

    std temp;
    char name[20];
    int len;
    char isHosteller;

    for(int i = 0; i < size; i++) {
        printf("Entry of Record %d: \n", i+1);
        printf("Enter student unique Id: ");
        scanf("%ld", &(temp.id));
        while(getchar() != '\n');

        printf("Enter student name: ");
        scanf("%s", name);
        while(getchar() != '\n');
        len = strlen(name);
        name[len-1] = '\0';
        strcpy(temp.name, name);

        printf("Enter the year of student: ");
        scanf("%d", &(temp.year));
        while(getchar() != '\n');

        while(1) {
            printf("Is he hosteller? (Y/N) : ");
            isHosteller = getchar();
            if(isHosteller == 'Y') {
                temp.isHost = 1;
                break;
            }
            else if(isHosteller == 'N') {
                temp.isHost = 0;
                break;
            }else {
                printf("Not a valid response...!\n");
            }
        }
        fwrite(&temp, sizeof(temp), 1, file);
    }
}

int main() {
    writeData();
}

// void readData() {
//     FILE* file;
//     file = fopen("./data/data.txt", "rb");

//     int size;
//     fread(&size, sizeof(size), 1, file);

// }

// int main() {
//     printf("Choices: \n");
//     printf("1. Write the Data\n");
//     printf("2. Read the Data\n");

//     int choice;
//     scanf("%d", &choice);
//     while(getchar() != '\n');

//     if(choice == 1) {
//         writeData();
//     }
//     else if(choice == 2){
//         readData();
//     }else{
//         printf("Not a valid choice");
//     }
// }

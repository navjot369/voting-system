#include <stdio.h>

void printOptionsWC(char options[][200], char title[], int total, int* curr) {
    printf("   %-40s (Count) \n", title);
    for(int i  = 0 ;i < total; i++) {
        printf("%d. %-40s %4d\n", i+1, options[i], *(curr+i));
    }
    printf("\n");
}

void printOptions(char options[][200], char title[], int total, int* curr) {
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



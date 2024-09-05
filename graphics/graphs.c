#include <stdio.h>
#include <math.h>

void RatioLine(int res[], int total) {
    int votes = 0;
    for(int i = 0; i < total; i++) votes += res[i];

    int ratio[total];
    for(int i = 0; i < total; i++) {
        ratio[i] = round(((res[i]*1.0)/votes)*100);
    }
    printf("\n%45s%s%45s\n", "", "Options(Votes)", "");
    for(int i = 0; i < total; i++) {
        printf("%*s%d(%d)%*s ", ratio[i]/2-2, "", i+1, res[i],ratio[i]/2-2,"");
    }
    printf("\n");
    char str1[101];
    for(int j = 0; j < 100; j++) str1[j] = '|';
    char str2[101];
    for(int j = 0; j < 100; j++) str2[j] = ':';
    int turn = 0;

    for(int  i = 0; i < total; i++) {
        if(turn == 1) {
            printf("%.*s", ratio[i], str1);
            turn = 0;
        }else{
            printf("%.*s", ratio[i], str2);
            turn = 1;
        }
    }
    printf("\n%47s%s%47s", "", "Ratio", "");
    printf("\n");
}

void HorizontalBar(int res[], int total) {
    int votes = 0;
    for(int i = 0; i < total; i++) votes += res[i];

    int ratio[total];
    int highestRatio = 0;
    for(int i = 0; i < total; i++) {
        ratio[i] = round(((res[i]*1.0)/votes)*100);
        if(ratio[i] > highestRatio) highestRatio = ratio[i];
    }
    highestRatio += 2;

    char str1[101];
    for(int j = 0; j < 100; j++) str1[j] = '>';
    char str2[101];
    for(int j = 0; j < 100; j++) str2[j] = ' ';
    int turn = 0;

    printf("(Options)%*s(Count)\n", highestRatio-1, "");
    for(int i = 0; i < total; i++) {
        printf("%5d    %.*s%.*s (%d)\n", i+1, ratio[i], str1, highestRatio-ratio[i]-2, str2, res[i]);
    }
}

// int main() {
//     int total = 4;
//     int arr[] = {5, 0, 0, 0};
//     RatioLine(arr, total);
//     HorizontalBar(arr, total);
// }

#include <stdio.h>
#include "include/InitialiseVoting.h"
#include "include/printOptions.h"
#include "include/takeVote.h"


int main() {
    printf("WELCOME...!! Press enter to start Voting.");
    getchar();

    startVoting();

    return 0;
}

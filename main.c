#include <stdio.h>
#include "voting/InitialiseVoting.h"
#include "utils/printOptions.h"
#include "utils/takeVote.h"
// #include "OpenVoting.h"
// #include "AnonymousVoting.h"


int main() {
    printf("WELCOME...!! Press enter to start Voting. \n");
    getchar();
    
    startVoting();

    return 0;
}
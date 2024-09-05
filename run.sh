#!/bin/bash

gcc -c utils/printOptions.c -o printOptions.o
gcc -c utils/takeVote.c -o takeVote.o
gcc -c voting/AnonymousVoting.c -o AnonymousVoting.o
gcc -c voting/OpenVoting.c -o OpenVoting.o
gcc -c voting/InitialiseVoting.c -o InitialiseVoting.o

ar rcs Voting.a InitialiseVoting.o AnonymousVoting.o OpenVoting.o printOptions.o takeVote.o
rm InitialiseVoting.o AnonymousVoting.o OpenVoting.o printOptions.o takeVote.o

gcc main.c -L. Voting.a
./a.out

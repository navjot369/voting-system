@echo off

gcc "-c" "graphics\graphs.c" "-o" "graphs.o"
gcc "-c" "utils\printOptions.c" "-o" "printOptions.o"
gcc "-c" "utils\takeVote.c" "-o" "takeVote.o"
gcc "-c" "utils\getResult.c" "-o" "getResult.o"
gcc "-c" "utils\clearScreen.c" "-o" "clearScreen.o"
gcc "-c" "voting\AnonymousVoting.c" "-o" "AnonymousVoting.o"
gcc "-c" "voting\OpenVoting.c" "-o" "OpenVoting.o"
gcc "-c" "voting\InitialiseVoting.c" "-o" "InitialiseVoting.o"
ar "rcs" "Voting.a" "InitialiseVoting.o" "graphs.o" "AnonymousVoting.o" "OpenVoting.o" "printOptions.o" "clearScreen.o" "takeVote.o" "getResult.o"
DEL  "InitialiseVoting.o" "AnonymousVoting.o" "OpenVoting.o" "printOptions.o" "clearScreen.o" "takeVote.o" "getResult.o" "graphs.o"
gcc "main.c" "-L." "Voting.a"
./a.out

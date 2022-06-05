// header file, where we declare all the functions, global variants, #max_size
//Name:Gili Wolf
//TZ:315144907
//Course: 80-515-09/11

#include <iostream>
#include <time.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define NUM_BOATS 5

// WATER_UNBOMBED = 0 , WATER_BOMBED = 1, SHIP_UNBOMBED = 2, SHIP_BOMBED = 3
enum { WATER_UNBOMBED, WATER_BOMBED, SHIP_UNBOMBED, SHIP_BOMBED };
// vertical = 0; horizontal = 1
enum { VERTICAL, HORIZONTAL };
// display[0],[2]= X (water/ ship unbombed), display[1]= '-' (water bombed), display [3] = '*' (ship bombed)
const char display[] = { 'X', '-', 'X', '*' };
// size of boats large to small
const int boats[] = { 5,4,3,3,2 };

bool CheckLocation(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight, int direction, int x_coord, int y_coord, int boatSize);
void PlaceBoat(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight, int direction, int x_coord, int y_coord, int boatSize);
void init_boats(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight);
void initBoard(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight);
int makeVisualBoard(int board[MAX_SIZE][MAX_SIZE], char VisualBoard[MAX_SIZE][MAX_SIZE], int x_coord, int y_coord);
void printBoard(const int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight);
void playGame(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight, int numSteps);



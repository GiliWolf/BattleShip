
//Name:Gili Wolf
//TZ:315144907
//Course: 80-515-09/11

#include "battleship_dec.h"

int main() 
{
	int Board[MAX_SIZE][MAX_SIZE];
	initBoard(Board, 10, 10);
	printBoard(Board, 10, 10);


	char answer = 0;

	do {
		playGame(Board, 10, 10, 0);
		do {
			std::cout << "Do you want to play again? (y/n)";
			std::cin >> answer;
		} while ((answer != 121) && (answer != 110));
	} 	while (answer == 121);


}
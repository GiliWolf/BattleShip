//Name:Gili Wolf
//TZ:315144907
//Course: 80-515-09/11

#include "battleship_dec.h"


// needs to return F = 0 or T =1  if the boat can "fit" in the board 
bool CheckLocation(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight, int direction, int x_coord, int y_coord, int boatSize) {

	// VERTICAL 
// check if not out of board 
	if (((x_coord + boatSize) < 11) && (direction == 0)) {
		// check left column 
		if (((y_coord - 1) >= 0) && ((x_coord - 1) >= 0)) {
			for (int i = (x_coord - 1); i <= (x_coord + boatSize); i++) {
				if (board[i][y_coord - 1] == 1) { return 0; }
			}
		}
		else if (((y_coord - 1) >= 0) && ((x_coord - 1) == (-1))) {
			for (int i = (x_coord); i <= (x_coord + boatSize); i++) {
				if (board[i][y_coord - 1] == 1) { return 0; }
			}
		}


		//check same column 
		if ((x_coord - 1) >= 0) {
			for (int i = (x_coord - 1); i <= (x_coord + boatSize); i++) {
				if (board[i][y_coord] == 1) { return 0; }
			}
		}
		else if ((x_coord - 1) == (-1)) {
			for (int i = (x_coord); i <= (x_coord + boatSize); i++) {
				if (board[i][y_coord] == 1) { return 0; }
			}
		}


		//chck right column 
		if (((y_coord + 1) <= 9) && ((x_coord - 1) >= 0)) {
			for (int i = (x_coord - 1); i <= (x_coord + boatSize); i++) {
				if (board[i][y_coord + 1] == 1) { return 0; }
			}
		}
		else if (((y_coord + 1) >= 9) && ((x_coord - 1) == (-1))) {
			for (int i = (x_coord); i <= (x_coord + boatSize); i++) {
				if (board[i][y_coord + 1] == 1) { return 0; }
			}
		}

	}
	else if (((x_coord + boatSize) > 10) && (direction == 0)) { return 0; }


	// HORIZONAL 

	// check if not out of board 
	if (((y_coord + boatSize) < 11) && (direction == 1)) {

		// CHECK ABOVE ROW 
		if (((x_coord - 1) >= 0) && ((y_coord - 1) >= 0)) {
			for (int i = (y_coord - 1);i <= (y_coord + boatSize); i++) {
				if (board[x_coord - 1][i] == 1) { return 0; }
			}
		}
		else if (((x_coord - 1) >= 0) && ((y_coord - 1) == (-1))) {
			for (int i = (y_coord);i <= (y_coord + boatSize); i++) {
				if (board[x_coord - 1][i] == 1) { return 0; }
			}
		}

		//CHECK SAME ROW 
		if ((y_coord - 1) >= 0) {
			for (int i = (y_coord - 1); i <= (y_coord + boatSize); i++) {
				if (board[x_coord][i] == 1) { return 0; }
			}
		}
		else if ((y_coord - 1) == (-1)) {
			for (int i = (y_coord); i <= (y_coord + boatSize); i++) {
				if (board[x_coord][i] == 1) { return 0; }
			}
		}

		//CHECK ROW BELOW 
		if (((y_coord - 1) >= 0) && ((x_coord + 1) <= 9)) {
			for (int i = (y_coord - 1);i <= (y_coord + boatSize); i++) {
				if (board[x_coord + 1][i] == 1) { return 0; }
			}
		}
		else if (((y_coord - 1) == (-1)) && ((x_coord + 1) <= 9)) {
			for (int i = (y_coord);i <= (y_coord + boatSize); i++) {
				if (board[x_coord + 1][i] == 1) { return 0; }
			}
		}

	}
	else if (((y_coord + boatSize) > 10) && (direction == 1)) { return 0; }



	// if everthing is good - 
	return 1;

}

// puts (1) in the board where the ship is (boat== T)
void PlaceBoat(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight, int direction, int x_coord, int y_coord, int boatSize) {

	// VERTICAL

	if (direction == 0) {
		for (int i = x_coord;i < (x_coord + boatSize);i++) {
			board[i][y_coord] = 1;
		}
	}



	// HORIZONAL 
	if (direction == 1) {
		for (int j = y_coord;j < (y_coord + boatSize);j++) {
			board[x_coord][j] = 1;
		}
	}
}




void init_boats(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight) {
	int x = 0, direction, x_coord, y_coord;
	while (x < NUM_BOATS) {
		//First choose vertical or horizontal;
		direction = rand() % 2;//0-1
		//std::cout << "the direction is" << direction << "  ";
		//random x-coordinate
		x_coord = rand() % MAX_SIZE; // 0-9
		//random y-coordinate
		y_coord = rand() % MAX_SIZE; //0-9
		if
			(CheckLocation(board, boardWidth, boardHeight, direction, x_coord, y_coord, boats[x])
				) {
			PlaceBoat(board, boardWidth, boardHeight, direction, x_coord, y_coord, boats[x]);
			x++;
			//std::cout << "the direction is" << direction<<"  ";
		}
	}
}

// put zeros in Board
void initBoard(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight) {
	for (int i = 0; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			board[i][j] = 0;
		}
	}
	init_boats(board, 10, 10);
}

// display[0],[2]= X (water/ ship unbombed), display[1]= '-' (water bombed), display [3] = '*' (ship bombed)
//const char display[] = { 'X', '-', 'X', '*' };

int makeVisualBoard(int board[MAX_SIZE][MAX_SIZE], char VisualBoard[MAX_SIZE][MAX_SIZE], int x_coord, int y_coord) {

	// targer already attacted 
	if ((VisualBoard[x_coord][y_coord] == '*') || (VisualBoard[x_coord][y_coord] == '-')) {
		std::cout << "\nTarget has already been attacked. Please try again.\n";
		return 0;
	}

	// new target 
	if (VisualBoard[x_coord][y_coord] == 'X') {
		// water bombed
		if (board[x_coord][y_coord] == 0) {
			VisualBoard[x_coord][y_coord] = '-';
			for (int i = 0; i < MAX_SIZE; i++) {
				for (int j = 0; j < MAX_SIZE; j++) {
					std::cout << VisualBoard[i][j];
				}
				std::cout << "\n";
			}
			std::cout << "\nYou have missed the target.\n";
			return 1;
		}
		// ship bombed
		else if (board[x_coord][y_coord] == 1) {
			VisualBoard[x_coord][y_coord] = '*';
			for (int i = 0; i < MAX_SIZE; i++) {
				for (int j = 0; j < MAX_SIZE; j++) {
					std::cout << VisualBoard[i][j];
				}
				std::cout << "\n";
			}
			board[x_coord][y_coord] = 0;
			// check if Game over
			if (true) {
				int sum = 0;
				for (int i = 0; i < MAX_SIZE; i++) {
					for (int j = 0; j < MAX_SIZE; j++) {
						sum = sum + board[i][j];
					}
				}
				if (sum == 0) {
					
					return 3;
				}
			}
			std::cout << "\nHit!\n";
			return 2;

		}
	}



}


//PRINTS - SAME ROW NO SPACES ---> END LINE --> NEW ROW  
void printBoard(const int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight) {
	for (int i = 0; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			std::cout << 'X';
		}
		std::cout << "\n";
	}
	std::cout << "\n";

}

//GETS MATRIX FROM MAIN, AFTER EACH TURN IT PRINTS BOARD + UPDATES IT IN BOARD AND PRINTS NUMSTEPS
// IF Theres a hit  --> DONT COUNT IT IN NumSteps 
//Checks if game is over ( Anouther function? )
// If GameOver --. prints NumSteps 
// can change to BOOL 
void playGame(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight, int numSteps) {
	int x = 0;
	char y = 0;
	int option = 0;
	numSteps = 0;
	int tryAgain = 0;
	//Init Visual Board with 'X'
	char visualBoard[MAX_SIZE][MAX_SIZE] = { 0 };
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			visualBoard[i][j] = display[0];
		}

	}

	do {
		do {
			if (tryAgain) {
				std::cout << "Target does not exist. Please try again. \n";
			}
			std::cout << "Please enter coordinates of target:\n\n";
			std::cin >> y >> x;
			tryAgain++;
		} while ((x < 0) || (x > 10) || (y < 65) || (y > 74));


		int x_coord = (x - 1);
		int y_coord = y - 65;

		//if makeVisual = 0- get coordunates again, dont count Steps 'targer beem attacted  ; = 1 --  water bombed,  count Steps
		//, =2 -- hit, dont count steps  ,  = 3 -- game over , count steps 

		switch (option = makeVisualBoard(board, visualBoard, x_coord, y_coord)) {
		case 0: option == 0;
			break;
		case 1: option == 1;
			visualBoard[x_coord][y_coord] = '-';
			numSteps++;
			std::cout << "Number of steps:" << numSteps << "\n";
			break;
		case 2: option == 2;
			visualBoard[x_coord][y_coord] = '*';
			std::cout << "Number of steps:" << numSteps << "\n";
			break;
		case 3: option == 3;
			std::cout << "\nHit!\n" << "Number of steps:" << numSteps<<"\n";
		    std::cout << "Game is over!\n";
			break;
		}
		if (option == 3) { break; }
		tryAgain = 0;
	} while ((option == 0) || (option == 1) || (option == 2));

	std::cout << "It took you " << numSteps << " turns to complete your mission. ";

}
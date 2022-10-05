// Name: Gomoku.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the definition of the output operator, done, draw, turn, and print functions.

#include"Header.h"
#include"Gomoku.h"
#include<iomanip>

/*
* This is the constructor of the GomokuGame class if width and number to win is inputted. 
* It initializes the vector by pushing empty spaces into every position.
* Current player is set to B, longest_string_length is set to gomokuspace(4), and winNum is set to 5.
*/
GomokuGame::GomokuGame(unsigned int width_, unsigned int winNum_)
{
	winNum = winNum_;
	width = width_ + outer_width; //see Header.h for outer_width explanation
	height = width;
	
	for (unsigned int i = 0; i < (width * height); i++) {
		board.push_back(" ");
	}
	current = B;
	longest_string_length = gomokuspace; 
	
}


/*
* This is the Gomoku constructor if only the width is inputted
* If the input width is less than or equal to 5, the number needed to win is set to the width automatically
* Otherise, the number needed to win is set to 5. 
*/
GomokuGame::GomokuGame(unsigned int width_)
{
	if (width_ <= gomoku_win) {
		winNum = width_; 
	}
	else {
		winNum = gomoku_win; 
	}

	width = width_ + outer_width;
	height = width;
	
	for (unsigned int i = 0; i < (width * height); i++) {
		board.push_back(" ");
	}
	current = B;
	longest_string_length = gomokuspace;

}


/*
* This method allows the objects of type Gomoku to be printed. It prints out the board.
*/
ostream& operator<<(ostream& os, const GomokuGame& game) {
	unsigned int size = game.longest_string_length;
	unsigned int rowIndex = 0;
	for (unsigned int i = 0; i < game.height; i++) {
		rowIndex = game.height - i -1;
		os << setw(size)<<rowIndex;
		for (unsigned int j = 0; j < game.width; j++) {
			os << setw(size)<<(game.board)[(game.width * rowIndex) + j];
		}
		os << endl;
	}
	os << setw(size)<<" ";
	for (unsigned int i = 0; i < game.width; i++) {
		os << setw(size)<<i;
	}
	os << endl;
	return os;
}

/*
* This method prints the board
*/
void GomokuGame::print() {
	cout << *this;
}

/*
* This method checks if there is a winner in the game.
* It returns true if there's a winner, and false otherwise.
*/
bool GomokuGame::done() {


	//checks for winner in the rows
	unsigned int index = 0;
	for (unsigned int i = 1; i < height-1; i++) {
		for (unsigned int j = 1; j < width - winNum; j++) {
			index = width * i + j;
			bool found_winner = true; // boolean representing if winner is found starting at (i,j); initially set to true
			for (int k = 1; k < winNum; k++) {
				if (board[index].compare(" ") == 0 || board[index + k].compare(board[index]) != 0) {
					found_winner = false;
				}
			}
			if (found_winner){
				winner = board[index];
				return true;
			}
		}

	}

	unsigned int index2 = 0; 
	//checks for winner in the columns 
	for (unsigned int i = 1; i < height-winNum ; i++) {
		for (unsigned int j = 1; j < width - 1; j++) {
			index2 = width*i + j;
			bool found_winner2 = true; // boolean representing if winner is found starting at (i,j); initially set to true
			for (int k = 1; k < winNum; k++) {
				if (board[index2].compare(" ") == 0 || board[index2 + k*width].compare(board[index2]) != 0) {
					
					found_winner2 = false;
				}
				
			}
			if (found_winner2) {
				winner = board[index2];
				return true;

			}
		}
	}

	//checks for winner in the right diagonal 
	unsigned int index3 = 0;
	for (unsigned int i = 1; i < height - 1; i++) {
		for (unsigned int j = 1; j < width - 1; j++) {
			if (i + (winNum - 1) < height && j + (winNum - 1) < width) {
				index3 = width * i + j;
				bool found_winner3 = true; // boolean representing if winner is found starting at (i,j); initially set to true
				for (int k = 1; k < winNum; k++) {
					if (board[index3].compare(" ") == 0 || board[index3 + k * width + k].compare(board[index3]) != 0) {
						found_winner3 = false;
					}
				}
				if (found_winner3) {
					winner = board[index3];
					return true;
				}
			}
		}
	}
		//checks for winner in the left diagonal 
		for (unsigned int i = 1; i < height - 1; i++) {
			for (unsigned int j = 1; j < width - 1; j++) {
				if (i + (winNum - 1) < height && j - (winNum - 1) >= 0) {
					unsigned int index4 = width * i + j;
					bool found_winner4 = true; // boolean representing if winner is found starting at (i,j); initially set to true
					for (int k = 1; k < winNum; k++) {
						if (board[index4].compare(" ") == 0 || board[index4 + k * width - k].compare(board[index4]) != 0) {
							found_winner4 = false;
						}
					}
					if (found_winner4) {
						winner = board[index4];
						return true;


					}
				}
			}
		}
	
	return false;
}

/*
* This method checks if there is a draw in the game.
* It returns true if there is a draw, and false otherwise.
*/
bool GomokuGame::draw() {
	vector<string> boardCopy = board;
	vector<string> boardB = board;
	vector<string> boardW = board;

	for (unsigned int i = 1; i < height - 1; i++) {
		for (unsigned int j = 1; j < width - 1; j++) {
			int index = width * i + j;
			if (board[index].compare(" ") == 0) {
				boardB[index] = "B"; //fill in empty spaces of boardB with "B" (and same for W in the next line)
				boardW[index] = "W";
			}
		}
	}

	bool isDraw = true;//boolean for if the game is a draw
	//checks if a board with empty spaces filled with Bs would have a winner, then same for Ws
	board = boardB;
	if (done()) {
		isDraw = false;
	}

	board = boardW;
	if (done()) {
		isDraw = false;
	}

	board = boardCopy; //revert board back to what is was
	return isDraw;
}

/*
* This method allows the program to switch between players, while informing
* the user of whose turn it is by printing that information out. It also adds the move
* that the player makes to the desired position.
*/
int GomokuGame::turn() {
	unsigned int inputRow = 0;
	unsigned int inputCol = 0;

	//Checks for who is the current player, and prints it out 
	if (current == B) {
		cout << "It is Player Black Stone's turn" << endl;
	}
	else if (current == W) {
		cout << "It is Player White Stone's turn" << endl;
	}

	int result = prompt(inputRow, inputCol);

	//If needed, the move that the player makes is added to the position
	if (result == quit) {
		return quit;
	}
	else {
		if (current == B) {
			board[(width * inputCol) + inputRow] = "B";
		}
		else {
			board[(width * inputCol) + inputRow] = "W";
		}
	}

	//Prints the board with the updated position 
	cout << endl;
	cout << *this;
	cout << endl << endl;

	if (current == B) {
		cout << "Player Black Stone: ";
		current = W;
	}
	else if (current == W) {
		cout << "Player White Stone: ";
		current = B;
	}

	//Prints out the moves that the player has made by iterating through the vector. 
	for (unsigned int i = 0; i < height ; i++) {
		for (unsigned int j = 0; j < width; j++) {
			if (current == W && board[(width * j) + i] == "B") {
				cout << i << ", " << j << "; ";
			}
			else if (current == B && board[(width * j) + i] == "W") {
				cout << i << ", " << j << "; ";
			}
		}
	}

	cout << endl << endl;
	return success;
}
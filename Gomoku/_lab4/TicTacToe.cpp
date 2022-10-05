// Name: TicTacToe.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the definition of the output operator, done, draw, turn, and print functions. 

#include"Header.h"
#include"TicTacToe.h"

/*
* This is the constructor of the TicTacToeGame class.
* It initializes the vector by pushing empty spaces into every position.
* Current player is set to X and longest_string_length is set to the tictactoespace(2).
*/
TicTacToeGame::TicTacToeGame(unsigned int width_, unsigned int height_)
{
	width = width_; 
	height = height_; 
	for (unsigned int i = 0; i < (width * height); i++) {
		board.push_back(" ");
	}
	current = x;
	longest_string_length = tictactoespace;  
}

/*
* This method allows the objects of type TicTacToeGame to be printed. It prints out the board.
*/
ostream& operator<<(ostream& os, const TicTacToeGame& game) {
	unsigned int size = game.longest_string_length; 
	unsigned int rowIndex = 0;
	for (unsigned int i = 0; i < game.height; i++) {
		rowIndex = game.height - i - 1;
		os << rowIndex;
		for (unsigned int j = 0; j < game.width; j++) {
			os << (game.board)[(game.width * rowIndex) + j];
			os << " ";

		}
		os << endl;
	}
	for (unsigned int i = 0; i < game.width; i++) {
		os.width(size);
		os << i;
	}
	os << endl;
	return os;
}

/*
* This method prints the board 
*/
void TicTacToeGame::print() {
	cout << *this;
}

/*
* This method allows the program to switch between players, while informing
* the user of whose turn it is by printing that information out. It also adds the move
* that the player makes to the desired position.
*/
int TicTacToeGame::turn() {
	unsigned int inputRow = 0;
	unsigned int inputCol = 0;

	//Checks for who is the current player, and prints it out 
	if (current == x) {
		cout << "It is Player X's turn" << endl;
	}
	else if (current == o) {
		cout << "It is Player O's turn" << endl;
	}

	int result = prompt(inputRow, inputCol);

	//If needed, the move that the player makes is added to the position
	if (result == quit) {
		return quit;
	}
	else {
		if (current == x) {
			board[(width * inputCol) + inputRow] = "X";
		}
		else {
			board[(width * inputCol) + inputRow] = "O";
		}
	}

	//Prints the board with the updated position 
	cout << endl;
	cout << *this;
	cout << endl << endl;

	if (current == x) {
		cout << "Player X: ";
		current = o;
	}
	else if (current == o) {
		cout << "Player O: ";
		current = x;
	}

	//Prints out the moves that the player has made by iterating through the vector. 
	for (unsigned int i = 1; i < height - 1; i++) {
		for (unsigned int j = 1; j < height - 1; j++) {
			if (current == o && board[(width * j) + i] == "X") {
				cout << i << ", " << j << "; ";
			}
			else if (current == x && board[(width * j) + i] == "O") {
				cout << i << ", " << j << "; ";
			}
		}
	}

	cout << endl << endl;
	return success;
}

/*
* This method checks if there is a draw in the game.
* It returns true if there is a draw, and false otherwise.
*/
bool TicTacToeGame::draw() {

	//If there is a winner, there isn't a draw
	if (done()) {
		return false;
	}

	//Checks if there are moves still to be made 
	for (unsigned int i = 1; i < height - 1; i++) {
		for (unsigned int j = 1; j < width - 1; j++) {
			int index = (width * i) + j;
			if (board[index] == " ") {
				return false;
			}
		}
	}

	return true;
}

/*
* This method checks if there is a winner in the game.
* It returns true if there's a winner, and false otherwise.
*/
bool TicTacToeGame::done() {
	//checks for winner in the rows
	for (unsigned int i = 1; i < height - 1; i++) {
		int index = (width * i) +1;
		if (board[index].compare(" ") != 0 && board[index].compare(board[index + 1]) == 0 && board[index].compare(board[index + 2]) == 0) {
			winner = board[index];
			return true;
		}
	}

	//checks for winner in the columns 
	for (unsigned int i = 1; i < width - 1; i++) {
		int index = width + i;
		if (board[index].compare(" ") != 0 && board[index].compare(board[index + 5]) == 0 && board[index].compare(board[index + 10]) == 0) {
			winner = board[index];
			return true;
		}
	}

	//checks for winner in the right diagonal 
	if (board[6].compare(" ") != 0 && board[6].compare(board[12]) == 0 && board[6].compare(board[18]) == 0) {
		winner = board[6];
		return true;
	}

	//checks for winner in the left diagonal 
	if (board[8].compare(" ") != 0 && board[8].compare(board[12]) == 0 && board[12].compare(board[16]) == 0) {
		winner = board[8];
		return true;
	}

	return false;
}
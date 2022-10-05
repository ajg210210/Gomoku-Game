// Name: GameBase.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the definition of the checkGame, prompt, and play functions. 

#include<iostream>
#include "Gamebase.h"
#include<algorithm>
#include<sstream>
#include "Header.h"
#include"TicTacToe.h"
#include"Gomoku.h"
#include<exception>


using namespace std;

/*
* This method checks which game the user wants to play. 
* It also checks if the user provides the correct number of inputs. 
*/
GameBase* GameBase::checkGame(int argc, char* argv[]) {

	//Checks for the correct number of arguments (or within the bounds of the correct number of arguments)
	GameBase* empty = 0;
	if (argc < default_expected_args) {
		return empty;
	}
	else if(argc > expected_args_width_and_numWin) {
		cout << "Please only enter a maximum of 3 inputs. " << endl;
		return empty;
	}

	//Checks if the user has input "TicTacToe" explicitly. If so, the game starts. 
	if (strcmp(argv[game_Name], "TicTacToe") == 0) {
		try {
			if (argc != default_expected_args) {
				return empty;
			}
			GameBase* game = new TicTacToeGame(tictactoe_win + outer_width, tictactoe_win + outer_width);
			return game;
		}
		catch (bad_alloc) {
			return empty;
		}
	}

	//Checks if the user has input "Gomoku" explicitly.  
	else if (strcmp(argv[game_Name], "Gomoku") == 0) {
		try {

			//Checks if it's just "Gomoku"
			if (argc == default_expected_args) {
				GameBase* game2 = new GomokuGame(default_width, default_numWin); 
				return game2; //game starts
			}

			//Checks if it's just "Gomoku" with width input
			else if (argc == expected_args_width_only) {
				string str_width = argv[game_width];
				istringstream iss(str_width);
				int width; 
				//Checks if input is an integer
				if (!(iss >> width)) { 
					cout << "Do not enter a non-number for the width." << endl;
					// the directions say to have a unique return failure value for if there's a negative number,
					//but on Piazza Prof. Shidal said we can have the same failure value for every command line error
					return empty;
				}
				else if (width <= 0) {
					cout << "Please don't enter 0 or a negative number. " << endl;
					
					return empty;
				}
				else if (width < 3) {
					cout << "Please enter a width of the gamebaord above 3." << endl;
					
					return empty;
				}
				else {
					GameBase* game2 = new GomokuGame(width);
					return game2;
				}	
			}

			//Checks if it's "Gomoku" with the width and number needed to win
			else if (argc == expected_args_width_and_numWin) {
				string str_width2 = argv[game_width];
				istringstream iss2(str_width2);
				string str_numWin = argv[game_numWin];
				istringstream iss3(str_numWin);
				int width2, numWin;
				//Checks if both inputs are integers
				if (!((iss2 >> width2) && (iss3 >> numWin))) {
					cout << "Do not enter a non-integer for the width or the number of connected pieces needed to win." << endl;
					return empty;
				}
				else if (width2 <= 0 || numWin <= 0) {
					cout << "Please don't enter 0 or a negative number. " << endl;
					return empty;
				}
				else if (width2 < 3 || numWin < 3) {
					cout << "Please enter a width and number of connected pieces to win above 3." << endl;
					
					return empty;
				}
				else if (numWin > width2) {
					cout << "The width of the gameboard must be at least the number of connected pieces to win. " << endl;
					
					return empty;
				}
				else {
					GameBase* game2 = new GomokuGame(width2, numWin);
					return game2;
				}
			}

			return empty;
		}
		catch (bad_alloc) {
			return empty;
		}
	}
	else {

		return empty;
	}
}


/*
* This method prompts the user for the position of their desired move or their desire to quit.
* If the user does not provide a valid input,they are re-prompted until they input something valid.
*/
int GameBase::prompt(unsigned int& inputRow, unsigned int& inputCol) {

	string input;
	bool valid = false;

	/*
	* Steps of the while loop
	* (1) Ask user for an input.
	* (2) If it is "quit," return immediately. Otherwise, find the comma and replace it with an empty space.
	* (3) Use stringstream to extract the inputs
	* (4) Condtions that would lead to a re-prompt include formatting issues, index out of range, and inserting at a position
	* that already has been used.
	*/
	while (!valid) {

		int output = success;

		cout << "Please type a coordinate <x-coordinate,y-coordinate>, or <quit> to quit the game" << endl;

		cin >> input;

		if (input.compare("quit") == 0 || input.compare("Quit") == 0) {
			return quit;
		}

		if (input.find(",") == string::npos) {
			output = invalidInput;
		}
		else {
			replace(input.begin(), input.end(), ',', ' ');
		}

		stringstream string_input(input);
		if (!(string_input >> inputRow)) {
			output = invalidInput;
		}
		if (!(string_input >> inputCol)) {
			output = invalidInput;
			cout << "Input format is incorrect. Please insert in valid format." << endl;
			continue;
		}
		if (inputRow<1 || inputCol<1 || inputRow>height - 2 || inputCol>height - 2) {
			output = outOfRange;
		}
		else if (board[(width * inputCol) + inputRow] != " ") {
			output = alreadyExists;
		}

		if (output == success) {
			valid = true;
		}
		else if (output == invalidInput) {
			cout << "Input format is incorrect. Please insert in valid format." << endl;
		}
		else if (output == outOfRange) {
			cout << "Coordinates are out of range. Please insert a row and column between the values of 1 and 3 inclusive" << endl;
		}
		else if (output == alreadyExists) {
			cout << "The position that you are trying to play has already been taken. Please choose another location" << endl;
		}
	}
	return success;
}


/*
* This method runs the game by repeatedly calling turn to prompt the players to make moves.
* It also ends the game by declaring a winner or a draw.
*/
int GameBase::play() {
	cout << endl;
	print(); 

	bool valid = false;
	int numOfTurns = 0;
	int result = 0;

	//As long as there isn't a winner, draw, or quit, the players are re-prompted
	while (!valid) {
		if (turn() == quit) {
			cout << numOfTurns << " turns were played. The user quit." << endl;
			valid = true;
			result = quit;
		}
		numOfTurns++;
		if (done()) {
			valid = true;
			cout << winner << " won the game!" << endl;
			result = success;
		}
		if (draw()) {
			valid = true;
			cout << numOfTurns << " turns were played and no winning moves remain. It is a draw!" << endl;
			result = tie;
		}
	}
	return result;

}
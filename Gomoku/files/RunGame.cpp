
// This file contains the 'main' function. Program execution begins and ends there.
// It also defines and prints the usage function. 

#include <iostream>
#include "GameBase.h"
#include "Header.h"
#include"TicTacToe.h"
#include <new>

using namespace std;

//This method calls checkGame and determine which game should be played
//If a game is to be played, a shared pointer is created and play method is called. 
int main(int argc, char*argv[])
{
	GameBase* p = GameBase::checkGame(argc, argv);

	if (p == 0) {
		usage(argv[program_Name]); 
	}
	else {
		shared_ptr<GameBase> sp(p); 
		return sp->play(); 
	}

}

//The usage function gives instruction for users that do not enter any arguments. 
int usage(char* input) {
	cout << "This program plays a game of TicTacToe or Gomoku" << endl;
	cout << "The default TicTacToe game will be 3x3 with 3 connected pieces to win" << endl; 
	cout << "The default Gomoku game will be 19x19 with 5 connected pieces to win" << endl; 
	cout << "For the Gomoku Game, you can customize the board dimension and number of connected pieces to win" << endl; 
	cout << "The board dimension has to be at least 3, and the number of connected pieces to win has to be >=3 and <=dimension number" << endl; 
	cout << "If the number of connected pieces to win is not specified, it will be equal to the dimension# if the dimension#<=5 and 5 otherwise" << endl; 
	cout << "Usage: " << input << " <TicTacToe>" << " or"<< " <Gomoku>"<< " or"<<" <Gomoku Dimension#>" << " or"<<" <Gomoku Dimension# Win#>" << endl;
	return command_line_Error;
}


// Function : This file contains the declaration of the GomokuGame class. It includes the functions and variables
// associated with the class. 
// It also includes the enum of players B and W. 

#pragma once
#include"Header.h"
#include"GameBase.h"

/*
* This enumeration stores the value representing the players.
* This is used to switch between players in the game. 
*/
enum GomokuPlayers {
	B = 100,
	W = 200
};

/*
* This is the TicTacToeGame class declaration. It inherits from the class GameBase.
* Apart from the mandatory functions, I created a integer current and winNum in public that will allow
* the program to track the current player and winning number of the game throughout the methods.
*/
class GomokuGame :public GameBase {
public: 
	GomokuGame(unsigned int width_, unsigned int winNum_);
	GomokuGame(unsigned int width_);
	friend ostream& operator<<(ostream& os, const GomokuGame& game);
	virtual void print() override;
	virtual bool done();
	virtual bool draw(); 
	virtual int turn(); 
	int current;
	int winNum;
};

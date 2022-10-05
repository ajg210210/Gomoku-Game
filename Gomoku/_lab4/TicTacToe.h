// Name: TicTacToe.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the TicTacToeGame class. It includes the functions and variables
// associated with the class. 
// It also includes the enum of players X and O. 

#pragma once
#include"Header.h"
#include"GameBase.h"

/*
* This enumeration stores the value representing the players.
* This is used to switch between players in the game.
*/
enum TicTacToePlayers {
	x = 100,
	o = 200
};

/*
* This is the TicTacToeGame class declaration. It inherits from the class GameBase. 
* Apart from the mandatory functions, I created a integer current in public that will allow
* the program to track the current player throughout the methods.
*/
class TicTacToeGame :public GameBase {
public:
	TicTacToeGame(unsigned int width_, unsigned int height_);
	virtual void print() override;
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	friend ostream& operator<<(ostream& os, const TicTacToeGame& game);
	int current;
};
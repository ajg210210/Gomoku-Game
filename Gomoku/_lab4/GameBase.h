// Name: GameBase.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the GameBase class. It includes the functions and variables
// associated with the class. 

#pragma once
#include<vector>
#include<iostream>
#include<string>
#include"Header.h"

using namespace std;

/*
* This is the GameBase class declaration. 
* Apart from the mandatory functions, I created a string winnner in public that will allow
* the program to track the winner of the games. 
*/
class GameBase {
protected: 
	vector<string> board;
	unsigned int width;
	unsigned int height;
	unsigned int longest_string_length;
public: 
	virtual void print() = 0;
	virtual bool done() = 0; 
	virtual bool draw() = 0; 
	virtual int prompt(unsigned int& inputRow, unsigned int& inputCol);
	virtual int turn() = 0; 
	int play();
	static GameBase* checkGame(int argc, char* argv[]); 
	string winner;
};


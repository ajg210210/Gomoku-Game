// Name: Header.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the usage function. 
// It also includes the enum of the essential array indicies, different successes/failures, 
// and size of the longest_string_length for both games. 

#pragma once

/*
* This enumeration stores the return values of different successes/failures
*/
enum successAndFailure {
	success = 0, 
	quit = 10, 
	invalidInput = -20, 
	outOfRange = -30, 
	alreadyExists = -40, 
	tie = -50,
	command_line_Error = -60
};

/*
* This enumeration stores the size of the longest_string_length for both games, the default width and outer width(borders), and number of wins for Gomoku
*/
enum size {
	tictactoespace = 2, 
	gomokuspace = 4,
	default_width = 19,
	default_numWin = 5,
	outer_width = 2 // outer_width represents the extra width of the board caused by the blanks spaces on each side of the board
};

/*
* This enumeration stores the main index values of user input
*/
enum arrayIndices {
	program_Name = 0,
	game_Name = 1,
	game_width = 2,
	game_numWin = 3
	
};

/*
* This enumeration includes the index of the arguments that we may possibly encounter
*/
enum expected_arg {
	default_expected_args = game_Name + 1,
	expected_args_width_only = game_width + 1,
	expected_args_width_and_numWin = game_numWin + 1
};

/*
* This enumeration includes the default winning numbers for the two games
*/
enum default_win_num {
	tictactoe_win = 3, 
	gomoku_win = 5
};

int usage(char* input);

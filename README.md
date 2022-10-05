# Gomoku-Game


Using C++ with object oriented and inheritance ideas, I developed a fully functional game similar to tic-tac-toe, but allows user input for any board dimension and win length


This program simulates a game of TicTacToe and Gomoku. The user is repeatedly prompted to make a move until there is a winner, draw, or decision to quit. A GameBase class is created to organize the program. TicTacToeGame and GomokuGame classes are created to implement the details of the two games. 

For the draw function, we decided to create 2 deep copies of the board, replace the empty spaces with Bs in one of them, and replace the empty spaces with Ws in the other one. Then the function calls the done function on each of the 2 deep copies, and if either of them return true, then the draw function returns false. The idea behind this is that if you replace all empty spaces with one gamepiece and the game still does not have a winner, then the game is a draw.

Possible Program return values: 
Enums for these can be found in Header.h
0 - Success
10 - quit (player quits)
-50 - tie (there is a tie)
-60 - command_line_Error (returned when usage method is called)

Possible return values in the methods: 
-20 - invalidInput (user did not give a valid input)
-30 - outOfRange (coordinate inputted is out of range)
-40 - alreadyExists (position is occupied)

Program parameters and their default values: 
Enums for these can be found in Header.h
0 - program_Name 
1 - game_Name
2 - game_width
3 - game_numWin

Argc Values: 
Enums for these can be found in Header.h
game_Name + 1 - default_expected_args
game_width + 1 -	expected_args_width_only
game_numWin + 1 -	expected_args_width_and_numWin

Default number needed to win: 
3 - tictactoe_win (TicTacToe needs 3 to win)
5 -	gomoku_win (Gomoku needs 5 to win)

Default values for the two games: 
2 - tictactoespace (longest_string_length for TicTacToe)
4 - gomokuspace (longest_string_length for Gomoku)
19 - default_width (default width for Gomoku)
5 - default_numWin (default number needed to win for all Gomoku games with width greater than 5)
2 - outer_width (Border length for all games)

Player representation value association: 
Enums for these can be found in TicTacToe.h
100 - x
200 - o

Player representation value association: 
Enums for these can be found in Gomoku.h
100 - B
200 - W
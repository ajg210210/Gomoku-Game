Author: Young Lin and Ajay Gupta
CSE 332 - Lab 4

Program Description: 
This program simulates a game of TicTacToe and Gomoku. The user is repeatedly prompted to make a move until there is a winner, draw, or decision to quit. 
A GameBase class is created to organize the program. TicTacToeGame and GomokuGame classes are created to implement the details of the two games. 

Implementation Choices: 
Since we used borders for our TicTacToe board, the methods we created are tailored to this fact. As a result, for the Gomoku board, we also created borders in order to ease the implementation. For the longest string length, we had set values for both TicTacToe and Gomoku. Since both games only have one character for the item on the board, the numbers in the rows are the only concern. Since it is unlikely that the board is of width over 100, I had 4 as the Gomoku space. For the draw function, we decided to create 2 deep copies of the board, replace the empty spaces with Bs in one of them, and replace the empty spaces with Ws in the other one. Then the function calls the done function on each of the 2 deep copies, and if either of them return true, then the draw function returns false. The idea behind this is that if you replace all empty spaces with one gamepiece and the game still does not have a winner, then the game is a draw.

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

Warnings and Errors encounterd throughout the process: 
1. Signed/Unsigned mismatch. When I tried comparing an int with an unsigned int, a signed/unsigned mismatch warning occured. 
2. The draw function filled the board before we finished the game. We forgot to restore the original board before the return. 
3. I was unable to call checkGame in main because I did not scope into it. 
4. We had a debug assertion error because our done() function in Gomoku.cpp

Test Cases Ran for Gomoku and TicTacToe: 
1. I tried running the program with X/O and B/W winning via a row. The winner was returned, and the program stopped. 
2. I tried running the program with X/O and B/W winning via a column. The winner was returned, and the program stopped. 
3. I tried running the program with X/O and B/W winning via a diagonal. The winner was returned, and the program stopped. 
4. I tried running the program with a draw. A message indicating a draw was returned, and the program stopped. 
5. I tried running the program with a player quitting halfway. A message indicating the number of turns that occurred was printed, and the program stopped. 
6. I tried running the program with a player inserting only one integer. A message indicating incorrect formatting was returned. 
7. I tried running the program with a player inserting only one integer and one comma. A message indicating incorrect formatting was returned. 
8. I tried running the program with a player inserting only letters. A message indicating incorrect formatting was returned. 
9. I tried running the program with a player inserting negative coordinates. A message indicating out of range coordinates was returned. 
10. I tried running the program with a player inserting large coordinates. A message indicating out of range coordinates was returned. 
 
 
 
 Extra Credit

    We had to change our Gomoku.cpp, Gomoku.h, GameBase.cpp and Header.h classes in order to implement the extra credit. We changed Gomoku to have 2 overloaded
constructors: one that had just the width of the gameboard, and one that had the width and the number of connected pieces needed to win (numWin). In both constructors, we changed the width so that it would be the inputted width + 2 (the enum for 2  is outer_width). This is so that when the user inputs the width, we
will still have the outer ring of blank spaces around the board. We used a height variable for Gomoku before the extra credit, so we made height equal to the width
in both constructors. For the first constructor, we made numWin equal to the width if the width is less than 5 (our enum for the 5 is gomoku_win), and made numWin 
equal to 5 if the width is greater than 5. For the second constructor, width and numWin are equal to their parameters. In the done() function in Gomoku.cpp, we
changed our code so that it would work with the variable numWin. We changed the for loop bounds, and added for loops (the for loops with the variable “k”) so that
the program would check a connected row/column/diagonal with numWin length. 
    In Gamebase.cpp, we changed the checkGame() function so that it would take any of the different possible inputs, and either returned a null pointer with printed
out error messages, or called the correct Gomoku/TicTacToe constructor. Some more enums were added for the extra credit in the Header.h file.
We tested our changed program in many different ways, including testing possible invalid command lines (such as a negative width or a numWin greater than the
width), and simulating games with many different width and numWin values. The output produced by inputting “Gomoku 10 6” was a game in which the gameboard had
values from 0 to 11 (but only 1-10 could be used in the game), and the number of connected pieces needed to win was 6. We also were able to test the Gomoku draw()
function much easier with smaller gameboards.


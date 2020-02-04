================================================
              lab3  Readme file
================================================

code by Yidi Zhang     yidi.zhang@wustl.edu

This program enables two players play "tictactoe" on a 3*3 board. 
The procedures of the program includes:

	encapsulating game data within a class,
	prompting for and receiving user input for game moves,
	determining whether or not a move is valid, and if it is
	updating and displaying the new state of the game

And it repeatly prints out the board after each move.

/////////////////////////////////////////////////////////////////////////////////////////

Files include:
tictactoe.h
	header file for the source files.
	Declare a class TicTacToe.
	
game.cpp
	source file defines a class TicTacToe and several functions in the class
	which help to make moves and print the board repeatly.

lab3.cpp
	The main function of the program.

//////////////////////////////////////////////////////////////////////////////////////////

Errors may occur:
1. wrong input number
	This program requires 2 input. The first one is the file name 
	and the second one should be the input txt file.
	If input number is not 2, the program will return this error.

2. wrong argument name
	The argument passed to the program has to be "TicTacToe".
	Or the program will return this error.

/////////////////////////////////////////////////////////////////////////////////////////

Test cases and results

H:\cse332s-fl19-wustl\lab3-echozyd\lab3\Debug>lab3.exe
wrong input number

--------------------------------------------------------------------------------
H:\cse332s-fl19-wustl\lab3-echozyd\lab3\Debug>lab3.exe TicTacToe123
lab3.exe :correct usage is TicTacToe

--------------------------------------------------------------------------------
H:\cse332s-fl19-wustl\lab3-echozyd\lab3\Debug>lab3.exe TicTacToe
4
3
2
1
0
  0 1 2 3 4

Player X 's turn
do next move or enter 'quit' to quit
1,1

4
3
2
1   X
0
  0 1 2 3 4

Player X: 1,1;
Player O 's turn

do next move or enter 'quit' to quit
1.1

invalid command
do next move or enter 'quit' to quit
1.1,2.1

invalid command
do next move or enter 'quit' to quit
asdfadf

invalid command
do next move or enter 'quit' to quit
s,a

invalid command
do next move or enter 'quit' to quit
quit

1 turns has been played.
Player O decides to quit

------------------------------------------------------
H:\cse332s-fl19-wustl\lab3-echozyd\lab3\Debug>lab3.exe TicTacToe
4
3
2
1
0
  0 1 2 3 4

Player X 's turn
do next move or enter 'quit' to quit
1,2

4
3
2   X
1
0
  0 1 2 3 4

Player X: 1,2;
Player O 's turn
do next move or enter 'quit' to quit
1,2

There exists a piece on the location selected
Player O 's turn
do next move or enter 'quit' to quit
----------------------------------------------------------

......
...
Player X 's turn
do next move or enter 'quit' to quit
3,1

4
3
2   O   O
1   X X X
0
  0 1 2 3 4

Player X: 1,1;2,1;3,1;
Player X wins

----------------------------------------------------------

......
...
2,3

4
3   O X O
2   O X X
1   X O X
0
  0 1 2 3 4

Player X: 3,2;3,1;2,2;1,1;2,3;
No winner
9 turns has been played.



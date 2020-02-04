================================================
              lab2  Readme file
================================================

code by Yidi Zhang     yidi.zhang@wustl.edu

This program reads a text file and converts the information into
	1) dimension of the game board.
	2) game pieces that contain color, name, display and location
and prints out the game board.

/////////////////////////////////////////////////////////////////////////////////////////

Files include:

1. lab2.cpp
	The main function of the program.
	functions include: 
		usage: prints out the error message and guide for the user.
		toLowerCase: inputs a string and converts the string to lower case.
		main: runs the program.

2. lab2.h
	header file for the main source.

3. game_piece.cpp
	The source file defines a struct game_piece and include two function to covert 
	a enum of a color into string and vice versa.

4. game_piece.h
	header file for game_piece. 
	Declare a struct game_piece and two functions in game_piece.cpp

5. game_board.cpp
	The source file includes functions to read the imformation from the input txt file 
	and function to print the board.
	The function includes:
		read_dim: read 2 digit from the input file as the dimenson of the board.
		read_piece: read each line from the input file and convert the imformation as a game piece
			which includes color, name, display and location
		print_piece: print out each game piece on the board.

6. game_board.h
	hearder file for game_borad. Declare each function in the source file.

//////////////////////////////////////////////////////////////////////////////////////////

Errors may occur:

1. wrong input number
	This program requires 2 input. The first one is the file name 
	and the second one should be the input txt file.
	If input number is not 2, the program will return this error.

2. file doesn't exist
	The input txt file can not be found under this path.

3. unable to read dimension
	The program fails to read any dimension imformation through out the whole file.

4. can not read any well formed pieces
	The program fails to get any well formed game piece.

5. dimension doesn't match
	The size of the game board doesnt match with the size of vector 
	which includes game pieces' imformation

/////////////////////////////////////////////////////////////////////////////////////////

Test cases and results

input in command line: lab.exe gomoku.txt
'lab.exe' is not recognized as an internal or external command,
operable program or batch file.

---------------------------------------------------------------------------------
input in command line: lab2.exe
usage: <lab2.exe>
error found : wrong input number

---------------------------------------------------------------------------------
input in command line: lab2.exe 1.txt    /*1.txt does not exist under the path*/
usage: <lab2.exe>
error found : file doesn't exist

---------------------------------------------------------------------------------
input in command line: lab2.exe gomoku.txt
-------txt--------
 8 8
black stone X 0 0
black stone X 0 2
black stone X 1 1
black stone X 2 0
black stone X 2 2
black stone X 3 1
black stone X 4 0
black stone X 4 2
black stone X 5 1
black stone X 6 0
black stone X 6 2
black stone X 7 1
white stone O 0 6
white stone O 1 5
white stone O 1 7
white stone O 2 6
white stone O 3 5
white stone O 3 7
white stone O 4 6
white stone O 5 5
white stone O 5 7
white stone O 6 6
white stone O 7 5
white stone O 7 7
------------------
 O O O O
O O O O
 O O O O


X X X X
 X X X X
X X X X

---------------------------------------------------------------------------------
input in command line: lab2.exe no_game_piece.txt 
usage: <lab2.exe>
error found : can not read any well formed pieces
--------txt--------
3 3
red Xs X 5 0
red Xs X 7 2
red Xs X 3 1
red Xs X 7 5
red Xs X 4 2
blue Os O 7 1 
blue Os O 1 6 
blue Os O 2 8 
blue Os O 2 5 
-------------------

---------------------------------------------------------------------------------
input in command line: lab2.exe blanks_and_badly_formed.txt 
--------output--------
 XX
  X

----------------------

--------txt--------


asdfaddf
3 3 3
red Xs X 2 2
red Xs X 1 2
red Xs X 2 1
red Xs X 7 5
red Xs X 4 2
blue Os O 7 1 
blue Os O 1 6 
blue Os O 2 8 
blue Os O 2 5 
-------------------

---------------------------------------------------------------------------------
input in command line: lab2.exe tic-toc-toe.txt 
--------output--------
XXX
 X
X
----------------------

--------txt--------
3 3
red Xs X 0 0
red Xs X 0 2
red Xs X 1 1
red Xs X 1 2
red Xs X 2 2
blue Os O 0 1       /*blue is invalid here*/
blue Os O 1 0 
blue Os O 2 0 
blue Os O 2 2 
-------------------

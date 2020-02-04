CSE 504 lab4 

By:
Muzhou liu muzhouliu@wustl.edu
Yidi Zhang yidi.zhang@wustl.edu 

Files included:

1. lab4.cpp
    This file includes the main function of the whole project that could choose to run tictactoe game or gomoku game using the command line argument. 

2. game.h
    (Base) Class GameBase is decleared in this header file, and can be used to design all grid based board games. 
    (Derived) Class TicTac is decleared in this header file. 
	(Derived) Class Gomoku is decleared in this header file. 
	Ostream operator << overload is also decleared in this file. 

3. gameBase.cpp
   functions of class GameBase are inplemented in this file. 
	functions included:
		prompt: get input from command line and convert into usable coordinates
		play: the process of running a board game that based on a grid and play by turns. 
		done: a pure virtual function. 
		draw: a pure virtual function. 
		turn: a pure virtual function. 
		print: a pure virtual function.

4. tictactoe.cpp
    functions of class TicTacToe are inplemented in this file. 
	functions included:
	    done: check if any player wins the game. 
		draw: check if the board is full or someone has already win the game 
		turn: the action of players in each turn
		print: print out the game status on the board.
		

5. gomoku.cpp
    function of class gomoku are inplemented in this file. 
	functions included:
      done: check if any player wins the game. 
	  draw: check if the board is full or someone has already win the game 
	  turn: the action of players in each turn
	  print: print out the game status on the board. 


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Returns :
This program has 3 different ending satatus:
success(0): there is no error runing the code. Can see this if someone wins the game. 
QUIT(1): The game ends when some choose to quit. 
DRAW(100): The game ends when there is a draw.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Possible error could run into 

Code would return wrong_argument if user use wrong command line argument to start the game. 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Test cases:

wrong game name 

H:\504git\cse332s-fl19-wustl\lab4-arknights\lab4\x64\Debug>lab4.exe tictac
lab4.exe: wrong commend line arguments

wrong number of command line arguments 
H:\504git\cse332s-fl19-wustl\lab4-arknights\lab4\x64\Debug>lab4.exe
lab4.exe: wrong commend line arguments

TicTacToe quit 

H:\504git\cse332s-fl19-wustl\lab4-arknights\lab4\x64\Debug>lab4.exe TicTacToe
4
3
2
1
0
  0 1 2 3 4

Player X 's turn
Please enter the corrdnates of the next move to continue or quit to quit.

quit
0 turns has been played.
Player X decides to quit

x wins

Player X 's turn
Please enter the corrdnates of the next move to continue or quit to quit.

3,3
Player: X: 1,1;2,2;3,3;
4
3   O   X
2   O X
1   X
0
  0 1 2 3 4

Player X wins

TicTacToe tie

Player X 's turn
Please enter the corrdnates of the next move to continue or quit to quit.

3,2
Player: X: 1,1;2,1;2,2;1,3;3,2;
4
3   X O O
2   O X X
1   X X O
0
  0 1 2 3 4

No winner
9 turns has been played.


Gomoku quit 

19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
X  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19

This is Player B's turn
Please enter the corrdnates of the next move to continue or quit to quit.

quit
0 turns has been played.
Player B decides to quit


Gomoku win

This is Player B's turn
Please enter the corrdnates of the next move to continue or quit to quit.

5,5


19
18
17
16
15
14
13
12
11
10
9
8
7
6
5              B
4           B     W
3        B  W
2     B  W
1  B  W
X  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19
Player B : 1,1; 2,2; 3,3; 4,4; 5,5;

Player B wins



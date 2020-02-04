#pragma once

#include <string>
#include <vector>
#include <memory>
using namespace std;

enum tictactoe_utility {

	board_size_tic = 5, // board size is 5 
	full_count = 9, // total 9 space to use in tictac toe 

};

enum {
	name_argument = 1, // index of game name 
	name_program = 0, // index of file
	num_argument = 2, // should have 2 args

};


enum usage{
	success=0,
	wrong_argument=1,
	invalid_move=2,
	QUIT=99,
	DRAW=100,
};


class GameBase {
protected:
	int width, height;
	vector<string> board;
	unsigned int longest_string; // longest print size 
	string player;
	vector<string> players;
	unsigned int count;

public:
	static unique_ptr<GameBase> GameType(int argc, char* argv[]); // use unique_ptr 
	virtual bool done()=0;
	virtual bool draw()=0;
	virtual int turn()=0;
	int prompt(unsigned int& x, unsigned int& y);
	int play();
	virtual void print()=0;
};

class TicTacToe:public GameBase {

	string X_moves;
	string O_moves;

public:
	TicTacToe();
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	
	//int play();
	virtual void print() { cout << *this << endl; }

	friend ostream& operator << (ostream& out, const TicTacToe& game);
};


enum gomoku_utility {
	board_size = 20, // 20 row or col including the edge 
	game_index = 1, // game index 1 on argv[]
	exe_index = 0,
	col_dsp_w = 3, // column display width
	first_player = 0,
	second_player = 1,
};

class gomoku :public GameBase {
protected:
	std::string b_moves;
	std::string w_moves;
public:
	gomoku();
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print();


	friend ostream& operator<<(ostream& os, const gomoku& game);

};

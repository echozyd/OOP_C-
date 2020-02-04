#pragma once

#include <string>
using namespace std;

enum {
	num_argument = 2,
	num_row = 6,
	num_col = 6,
	full_count = 9,
	name_argument = 1,
	name_program = 0
};

enum usage{
	success=0,
	wrong_input_number,
	wrong_argument_name,
	invalid_move,
	QUIT,
	DRAW,
};




class TicTacToe {
	string board[6][6];

	unsigned int coo_x;
	unsigned int coo_y;

	unsigned int count;

	string player;

	string X_moves;
	string O_moves;

public:
	TicTacToe();
	bool done();
	bool draw();
	int turn();
	int prompt(unsigned int & x, unsigned int & y);
	int play();

	friend ostream& operator << (ostream& out, const TicTacToe& bd);
};
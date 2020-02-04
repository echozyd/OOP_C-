#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include "Game.h"

using namespace std;

gomoku::gomoku() {
	count = 0;
	player = "B";
	players = {"B", "W"};
	longest_string = col_dsp_w;

	for (int i = 0; i < gomoku_utility::board_size * gomoku_utility::board_size; i++) {
		board.push_back(" ");
	}

	
}


ostream& operator<<(ostream& os, const gomoku& game) {
	os << endl << endl;
	unsigned int index;

	for (int i = gomoku_utility::board_size-1; i > 0; i--) {

		for (int j = 0; j < gomoku_utility::board_size; ++j) {

			if (j == 0) {
				if (i < 10) { os << i << "  "; }
				else { os << i << " "; }
			}
			else{
				index = gomoku_utility::board_size * i + j;
				os << game.board[index] << "  ";
			}
		}
		os << endl;
	}
	// there is an X in the corner 
	os << "X" << "  ";
	// padding for the 1 digit or 2 digit 
	for (int k = 1; k < gomoku_utility::board_size; k++) {
		if (k < 10) { os << k << "  "; }
		else { os << k << " "; }
	}
	return os;
}

void gomoku::print() {
	cout << * this << endl;
}

bool gomoku::done() {
	bool if_win = false;
	for (int i = 1; i < gomoku_utility::board_size; i++) {
     // go through the board 
		for (int j = 1; j < gomoku_utility::board_size; j++) {
         unsigned int index = gomoku_utility::board_size * i + j;
		 
		    // 5 same piece in a row 
			if (j + 4 < gomoku_utility::board_size) {
				if_win = board[index] != " "
					&& board[index] == board[index + 1]
					&& board[index] == board[index + 2]
					&& board[index] == board[index + 3]
					&& board[index] == board[index + 4];
			}
			if (if_win) return true;

			// 5 same peice in a column 
			if (i + 4 < gomoku_utility::board_size) {
				if_win = board[index] != " "
					&& board[index] == board[index + 1 * gomoku_utility::board_size]
					&& board[index] == board[index + 2 * gomoku_utility::board_size]
					&& board[index] == board[index + 3 * gomoku_utility::board_size]
					&& board[index] == board[index + 4 * gomoku_utility::board_size];
			}
			if (if_win) return true;

			// 5 same piece like "\"
			if (j - 4 > 0 && i + 4 < gomoku_utility::board_size) {
				if_win = board[index] != " "
					&& board[index] == board[index + 1 * gomoku_utility::board_size - 1]
					&& board[index] == board[index + 2 * gomoku_utility::board_size - 2]
					&& board[index] == board[index + 3 * gomoku_utility::board_size - 3]
					&& board[index] == board[index + 4 * gomoku_utility::board_size - 4];
			}
			if (if_win) return true;

			// 5 same picec like "/"
			if (j + 4 < gomoku_utility::board_size && i + 4 < gomoku_utility::board_size) {
				if_win = board[index] != " "
					&& board[index] == board[index + 1 * gomoku_utility::board_size + 1]
					&& board[index] == board[index + 2 * gomoku_utility::board_size + 2]
					&& board[index] == board[index + 3 * gomoku_utility::board_size + 3]
					&& board[index] == board[index + 4 * gomoku_utility::board_size + 4];
			}
			if (if_win) return true;
		}


	}

	return if_win;
}

bool gomoku::draw() {
	bool draw_b, draw_w;
	draw_b = draw_w = true;
    // go through the board 
	for (int i = 1; i < gomoku_utility::board_size; i++) {
		for (int j = 1; j < gomoku_utility::board_size; j++) {

			unsigned int index = i * gomoku_utility::board_size + j;

			// check if opponent blocks a row
			if (j + 4 < gomoku_utility::board_size) {
				 draw_b = board[index] == "W"
					|| board[index + 1] == "W"
					|| board[index + 2] == "W"
					|| board[index + 3] == "W"
					|| board[index + 4] == "W";

				 draw_w = board[index] == "B"
					 || board[index + 1] == "B"
					 || board[index + 2] == "B"
					 || board[index + 3] == "B"
					 || board[index + 4] == "B";

			}
			if (!draw_b || !draw_w) return false;

			// check if opponent block a col
			if (i + 4 < gomoku_utility::board_size) {
				draw_b = board[index] == "W"
					|| board[index + 1 * gomoku_utility::board_size] == "W"
					|| board[index + 2 * gomoku_utility::board_size] == "W"
					|| board[index + 3 * gomoku_utility::board_size] == "W"
					|| board[index + 4 * gomoku_utility::board_size] == "W";

				draw_w = board[index] == "B"
					|| board[index + 1 * gomoku_utility::board_size] == "B"
					|| board[index + 2 * gomoku_utility::board_size] == "B"
					|| board[index + 3 * gomoku_utility::board_size] == "B"
					|| board[index + 4 * gomoku_utility::board_size] == "B";

			}
			if (!draw_b || !draw_w) return false;

			// check if upper-right block 
			if (j - 4 > 0 && i + 4 < gomoku_utility::board_size) {
				draw_b = board[index] == "W"
					|| board[index + 1 * gomoku_utility::board_size - 1] == "W"
					|| board[index + 2 * gomoku_utility::board_size - 2] == "W"
					|| board[index + 3 * gomoku_utility::board_size - 3] == "W"
					|| board[index + 4 * gomoku_utility::board_size - 4] == "W";

				draw_w = board[index] == "B"
					|| board[index + 1 * gomoku_utility::board_size - 1] == "B"
					|| board[index + 2 * gomoku_utility::board_size - 2] == "B"
					|| board[index + 3 * gomoku_utility::board_size - 3] == "B"
					|| board[index + 4 * gomoku_utility::board_size - 4] == "B";

			}
			if (!draw_b || !draw_w) return false;

			// check if upper-left block 
			if (j + 4 <gomoku_utility::board_size  && i + 4 < gomoku_utility::board_size) {
				draw_b = board[index] == "W"
					|| board[index + 1 * gomoku_utility::board_size + 1] == "W"
					|| board[index + 2 * gomoku_utility::board_size + 2] == "W"
					|| board[index + 3 * gomoku_utility::board_size + 3] == "W"
					|| board[index + 4 * gomoku_utility::board_size + 4] == "W";

				draw_w = board[index] == "B"
					|| board[index + 1 * gomoku_utility::board_size + 1] == "B"
					|| board[index + 2 * gomoku_utility::board_size + 2] == "B"
					|| board[index + 3 * gomoku_utility::board_size + 3] == "B"
					|| board[index + 4 * gomoku_utility::board_size + 4] == "B";

			}
			if (!draw_b || !draw_w) return false;
		}
	}
	// if come here no place to continue 
	return true;

}





int gomoku::turn() {
	++count;

	if (count % 2 == 0) { // step 1 by B and step2 by W
		player = players[second_player];
	}
	else {
		player = players[first_player];
	}
	cout << endl << "This is Player " << player << "'s turn" << endl;

	unsigned int x ;
	unsigned int y ;

	while (1) {
		// quit if input have quit 
		int prompt_out = prompt(x, y);
		if (prompt_out == QUIT) {
			return QUIT;
		}
		if (prompt_out == success) {
			if (0 < x && x < gomoku_utility::board_size && 0 < y && y < gomoku_utility::board_size) {
				// if sapace is empty, put in 
				// use index
				unsigned int index = y * gomoku_utility::board_size + x;

				if (board[index] == " ") { 
					board[index] = player;
					break;
				}
				else {
					cout << "That space was occupied." << endl;
				}
			}
			else {
				cout << "One or both of the input out or range." << endl;
			}
		}
	}



	//output the board

	this ->print();


	// prints out the moves the player has made store in private string
	stringstream ss;
	ss << x << "," << y << "; ";
	if (player == players[second_player]) {
		w_moves.append(ss.str());
		cout << "Player " << player <<" : " << w_moves << endl << endl;
	}
	else if (player == players[first_player]) {
		b_moves.append(ss.str());
		cout << "Player " << player << " : " << b_moves << endl << endl;
	}
	return success;
}




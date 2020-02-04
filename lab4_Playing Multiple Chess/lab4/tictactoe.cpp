#include <iostream>
#include "Game.h"
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>

TicTacToe::TicTacToe() {
	width = height = board_size_tic;
	longest_string = 1;
	count = 0;
	player = "X";
	players = { "X","O" };

	for (int i = 0; i < width * height; i++) { board.push_back(" "); }

}

bool TicTacToe::done() {
	// check whether any of the colomns are three in a colomn
	for (int col = 1; col < width - 1; ++col) {
		//make sure that they are not three space
		int index = col + width;
		if (board[index] == " ") {
			continue;
		}
		else if (board[index] == board[index + width]
			&& board[index] == board[index + 2 * width]) {
			return true;
		}
	}

	// check whether any of the rows are three in a row
	for (int row = 1; row < height - 1; ++row) {
		int index = row * 5 + 1;
		if (board[index] == " ") {
			continue;
		}
		else if (board[index] == board[index + 1]
			&& board[index] == board[index + 2]) {
			return true;

		}
	}

	// check whether the diagonals are three in a row
	unsigned int middle = 12;
	if (board[middle] == " ") {
		return false;

	}
	else if (board[middle] == board[middle - (width + 1)] && board[middle] == board[middle + (width + 1)]) {
		return true;

	}
	else if (board[middle] == board[middle - (width - 1)] && board[middle] == board[middle + (width - 1)]) {
		return true;
	}

	return false;
}

bool TicTacToe::draw() {

	// in the program, if the board is full of pieces and nobody wins, return draw.
	if (count == full_count || this->done()) {
		return true;
	}
	else {
		return false;
	}

}

int TicTacToe::turn() {

	//alternate the turn;
	count++;
	unsigned int tempX;
	unsigned int tempY;
	int ind = count % 2;
	//if count is an odd number, player is X. Otherwise, player should be O.
	player = players[abs(ind - 1)];

	//Loop until a valid move is made.
	while (1) {

		cout << "Player " << player << " 's turn" << endl;
		if (prompt(tempX, tempY) == QUIT) {
			return QUIT;
		}

		if (tempX > (unsigned int)0 && tempX < (unsigned int)(width - 1) && tempY > (unsigned int)0 && tempY < (unsigned int)(height - 1)) {
			//print the new piece on the board if it is valid.
			if (board[5 * tempY + tempX] == " ") {
				board[5 * tempY + tempX] = player;
				break;
			}
			else {
				cout << "There exists a piece on the location selected" << endl;
			}
		}
		else {
			cout << "invalid move" << endl;
		}
	}

	//store the previous moves for each players.
	stringstream this_move;
	this_move << tempX << "," << tempY << ";";
	if (player == "X") {
		X_moves = X_moves + this_move.str();
		cout << "Player: " << player << ": " << X_moves << endl;
	}
	else if (player == "O") {
		O_moves = O_moves + this_move.str();
		cout << "Player: " << player << ": " << O_moves << endl;
	}



	//output the board
	print();

	return 0;

}

ostream& operator <<(ostream& out, const TicTacToe& game) {

	int width = game.width;
	int height = game.height;
	//use digit to store the number of spaces each piece need including the " "
	unsigned int digit = game.longest_string + 1;


	for (int i = height - 1; i >= 0; --i) {

		for (int j = 0; j < width; ++j) {
			int index = i * width + j;
			if (j == 0) {
				out << i << setw(digit) << game.board[index] << setw(digit);
			}
			else {
				out << game.board[index] << setw(digit);
			}

		}
		out << " " << endl;
	}

	out << setw(digit + 1);

	for (int j = 0; j < width; j++) { out << j << setw(digit); }
	out << endl;

	return out;
}
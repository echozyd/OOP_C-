
#include <iostream>
#include "tictactoe.h";
#include <string>
#include <sstream>

using namespace std;

TicTacToe::TicTacToe() {
	count = 0;
	coo_x = 10000;
	coo_y = 10000;
	player = "X";
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			board[i][j] = " ";
		}
	}
	board[0][5] = "4";
	board[0][4] = "3";
	board[0][3] = "2";
	board[0][2] = "1";
	board[0][1] = "0";
	board[1][0] = "0";
	board[2][0] = "1";
	board[3][0] = "2";
	board[4][0] = "3";
	board[5][0] = "4";

}




ostream& operator <<(ostream& out, const TicTacToe & game) {

	for (int i = num_row-1; i>=0; --i) {
		for (int j = 0; j < num_col; ++j) {

			out << game.board[j][i] << " ";
		}
		out << " " << endl;
	}
	return out;
}


bool TicTacToe::done() {

	// check whether any of the colomns are three in a colomn
	for (int col = 2; col<num_col; ++col) {
		//make sure that they are not three space
		if (board[col][3] == " ") {
			continue;
		}
		else if (board[col][2] == board[col][3]
			&& board[col][3] == board[col][4]) {
			return true;
		}
	}

	// check whether any of the rows are three in a row
	for (int row = 2; row < num_row-1; ++row) {
		if (board[3][row] == " ") {
			continue;
		}
		else if (board[2][row] == board[3][row]
			&& board[3][row] == board[4][row]) {
			return true;

		}
	}

	// check whether the diagonals are three in a row
	if (board[3][3] == " ") {
		return false;

	}
	else if (board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
		return true;

	}
	else if (board[3][3] == board[2][4] && board[3][3] == board[4][2]) {
		return true;
	}

	return false;
}


bool TicTacToe::draw() {

	count = count + 1;

	// in the program, if the board is full of pieces and nobody wins, return draw.
	if (count == 9 || this->done()) {
		return true;
	}
	else {
		return false;
	}
}

int TicTacToe::prompt(unsigned int& x, unsigned int& y) {
	string input;

	//continue the loop until the player quits or a valid move has been made.
	while (1) {
		cout << "do next move or enter 'quit' to quit" << endl;
		//getline from the command line.
		getline(cin, input);
		cout << endl;

		string temp;

		istringstream iss(input);

		//convert the iss to a string.
		while (iss) {
			string temp_in_string;
			iss >> temp_in_string;
			temp = temp + temp_in_string;

		}
		//if a player enters "quit", return quit.
		if (temp == "quit") {
			return QUIT;
		}

		int len = temp.size();

		string CommaCheck;

		stringstream ss;
		ss << temp[1] << "";
		ss >> CommaCheck;
		
		/*check if the input's length is 3 and the middle of the input is a comma.
		If not, print "invalid command"
		*/
		if (CommaCheck == "," && len == 3) {

			stringstream sss;
			sss << temp[0] << " " << temp[2];
			//check if 2 integer can be successfully extracted. If not, print "invalid command"
			if (sss >> x >> y) { break; }
			else { cout << "invalid command" << endl; }
		}
		else {
			cout << "invalid command" << endl;
		}
	}

}

int TicTacToe::turn() {
	unsigned int& x = coo_x;
	unsigned int& y = coo_y;
	unsigned int tempX;
	unsigned int tempY;
	//Loop until a valid move is made.
	while (1) {
		cout << "Player " << player << " 's turn" << endl;
		if (prompt(x, y) == QUIT) {
			return QUIT;
		}

		tempX = x;
		tempY = y;


		if (tempX > 0 && tempX < 4 && tempY>0 && tempY < 4) {
			//print the new piece on the board if it is valid.
			if (board[tempX + 1][tempY + 1] == " ") {
				board[tempX + 1][tempY + 1] = player;
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
	this_move << x << "," << y << ";";
	if (player == "X") {
		X_moves = X_moves + this_move.str();
	}
	else if (player == "O") {
		O_moves = O_moves + this_move.str();
	}

	//output the board
	cout << *this << endl;



	//alternate the turn
	if (player == "X") {
		cout << "Player " << player << ": " << X_moves << endl;
		player = "O";
	}
	else {

		cout << "Player " << player << ": " << O_moves << endl;
		player = "X";
	}

	return 0;

}


int TicTacToe::play() {

	//output the initial board

	cout << *this << endl;

	while (1) {
		if (this->turn() == QUIT) {
			cout << count << " turns has been played." << endl;
			cout << "Player " << player << " decides to quit" << endl;
			return QUIT;
		}
		/*After a valid move is made, check if the player has won.
		If so, print the message showing the player wins and end the game.
		Since we have alternated the turn in turn(), the winner should be the last player.
		*/
		if (this->done()) {
			if (player == "X") {
				cout << "Player " << "O" << " wins" << endl;
			}
			else {
				cout << "Player " << "X" << " wins" << endl;
			}

			return 0;
		}

		if (this->draw()) {

			cout << "No winner" << endl;
			cout << count << " turns has been played." << endl;
			return DRAW;

		}

	}

}





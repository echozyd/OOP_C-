// lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "lab2.h"
#include "game_piece.h"
#include "game_board.h"
using namespace std;

int usage(char* prog_name, string str, enum errorMsg err_) {
	cout << "usage: <" << prog_name << ">" << endl;
	cout << "error found : ";
	cout << str << endl;
	return err_;
}

string toLowerCase(string& str) {
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}
	return str;
}


int main(int argc, char* argv[]) {
	if (argc != expect_input) {
		string str = "wrong input number";
		return usage(argv[prog_name], str, wrong_input_num);
	}
	
	ifstream inputfile(argv[inputfile]);
	if (!inputfile.is_open()) {
		string str = "file doesn't exist";
		return usage(argv[prog_name], str, file_not_exist);
		
	}

	unsigned int ver, hor;
	int read_dim_error = read_dim(inputfile, hor, ver);
	while (read_dim_error == no_dimension) {
		read_dim_error = read_dim(inputfile, hor, ver);
	}
	if (read_dim_error == unable_to_read_line) {
		string str = "unable to read dimension";
		return(usage(argv[prog_name], str, no_dimension));
	}

	game_piece default_piece(no_color, "empty", " ");
	vector<game_piece> pieces;
	unsigned int board_size = ver * hor;
	for (unsigned int i = 0; i < board_size; ++i) {
		pieces.push_back(default_piece);
	}

	int read_piece_error=read_piece(inputfile, pieces, hor, ver);
	if (read_piece_error == no_game_pieces) {
		string str = "can not read any well formed pieces";
		return(usage(argv[prog_name], str, no_game_pieces));
	}

	int print_board_error = print_piece(pieces, hor, ver);
	if (print_board_error == dimension_not_match) {
		string str = "dimension doesn't match";
		return(usage(argv[prog_name], str, dimension_not_match));
	}

	inputfile.close();
	return(success);
}
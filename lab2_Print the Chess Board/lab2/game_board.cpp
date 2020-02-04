
#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include "lab2.h"
#include "game_piece.h"
#include "game_board.h"
#include<vector>

using namespace std;


int read_dim(ifstream& ifs, unsigned int& hor, unsigned int& ver) {
	string str;
	if (getline(ifs, str)) {
		istringstream iss(str);
		if (iss >> hor >> ver) {
			return success;
		}
		else {
			return no_dimension;
		}
	}
	else {
		return unable_to_read_line;
	}

}


int read_piece(ifstream& ifs, vector<game_piece>& vec, unsigned int& hor, unsigned int& ver) {
	string str;
	string color;
	string name;
	string display;
	int x, y;
	int count = 0;
	while (getline(ifs, str)) {
		istringstream iss(str);
		if (iss >> color >> name >> display >> x >> y) {
			color=toLowerCase(color);
			game_piece new_piece(str_to_enum(color), name, display);
			if (new_piece.color_ != invalid_color) {
				if ((x < hor) && (y < ver)) {
					int index = hor * y + x;
					vec[index] = new_piece;
					count = 1;
				}
			}

		}

	}
	if (count == 0) {
		return no_game_pieces;
	}
	else {
		return success;
	}
}


int print_piece(const vector<game_piece>& vec, unsigned int& hor, unsigned int& ver) {
	if (vec.size()!= hor*ver) {
		return dimension_not_match;
	}
	else {
		//int count = 0;
		int board_size = hor * ver;
		for (int i = ver - 1; i >= 0; i--) {
			for (unsigned int j = 0; j <= hor - 1; j++) {
				int location = i * hor + j;
				cout << "" << vec[location].display_ << "";
				//count += 1;
			}
			cout << endl;

		}

		return success;

	}
}
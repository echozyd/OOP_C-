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

int read_dim(ifstream& ifs, unsigned int& hor, unsigned int& ver);

int read_piece(ifstream& ifs, vector<game_piece>& vec, unsigned int& hor, unsigned int& ver);

int print_piece(const vector<game_piece>& vec, unsigned int& hor, unsigned int& ver);
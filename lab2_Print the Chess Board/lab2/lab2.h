#pragma once
#ifndef LAB2_H
#define LAB2_H
#include<string>
#include "game_piece.h"
#include "game_board.h"
using namespace std;


enum errorMsg
{
	success=0,
	file_not_exist=1,
	no_dimension=2,
	unable_to_read_line=3,
	wrong_input_num=4,
	no_game_pieces=5,
	dimension_not_match=6,
};

enum utility {
	expect_input = 2,
	inputfile=1,
	prog_name=0
};




int usage(char* prog_name, string str, enum errorMsg err);


string toLowerCase(string& str);

#endif
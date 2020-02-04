
#include <string>
#include <iostream>
#include "game_piece.h"
using namespace std;

game_piece::game_piece(enum piece_color color, string name, string display)
	:color_(color), name_(name), display_(display) {}




string enum_to_str(enum piece_color color) {
	string strcolor;
	if (color == piece_color::red)
	{
		strcolor = "red";
	}
	else if (color == piece_color::white)
	{
		strcolor = "white";
	}
	else if (color == piece_color::black)
	{
		strcolor = "black";
	}
	else if (color == piece_color::invalid_color)
	{
		strcolor = "invalid color";
	}
	else if (color == piece_color::no_color)
	{
		strcolor = "no color";
	}
	return strcolor;
}


enum piece_color str_to_enum(string str) {
	enum piece_color enum_color;
	if (str == "red")
	{
		enum_color = piece_color::red;
	}
	else if (str == "white")
	{
		enum_color = piece_color::white;
	}
	else if (str == "black")
	{
		enum_color = piece_color::black;
	}
	else if (str == " ")
	{
		enum_color = piece_color::no_color;
	}
	else
	{
		enum_color = piece_color::invalid_color;
	}
	return(enum_color);
}
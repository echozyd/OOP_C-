#pragma once
#include <string>
using namespace std;

enum piece_color
{
	red,
	black,
	white,
	invalid_color,
	no_color,
};

struct game_piece {
	game_piece(enum piece_color color, string name, string display);
	enum piece_color color_;
	string name_;
	string display_;
};

string enum_to_str(enum piece_color color);
enum piece_color str_to_enum(string str);



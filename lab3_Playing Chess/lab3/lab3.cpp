// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "tictactoe.h";
#include <string>
#include <sstream>

using namespace std;



int main(int argc, char* argv[]) {
	if (argc != num_argument) {
		cout << "wrong input number" << endl;
		return wrong_input_number;
	}
	if (argv[name_argument] != string("TicTacToe")) {
		cout << argv[name_program]<<": correct usage is TicTacToe" << endl;
		return wrong_argument_name;
	}
	else {
		TicTacToe board1;
		return board1.play();
	
	}



}
// lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"
#include <string>
#include <sstream>
#include <vector>

int main(int argc, char* argv[]) {
	// check if the input contains a correct game name
	// if valid start the game 
	// else output usage message. 

	unique_ptr<GameBase> gb = GameBase::GameType(argc, argv);

	if (gb != 0) {
		//unique_ptr<GameBase> ptr(gb);
		return (*gb).play();
	}
	else {
		cout << argv[name_program] << ": wrong commend line arguments" << endl;
		return wrong_argument;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


#include <iostream>
#include "Game.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;



int GameBase::prompt(unsigned int &x, unsigned int &y) {
	unsigned int tempx;
	unsigned int tempy;


	cout << "Please enter the corrdnates of the next move to continue or quit to quit." << endl << endl;

	string line;
	cin >> line;
	if (line == "quit") {
		return QUIT;
	}

	try {
		size_t comma = line.find(",");
		line.replace(comma, 1, " ");
		istringstream ss(line);
		if (ss >> tempx >> tempy) {
			//valid input
			//continue
			x = tempx;
			y = tempy;
			return success;
		}
		else {
			throw exception("Your input is invalid.");
		}
	}
	// keep prompt until we get a valid input
	catch (exception e) {
		cout << "Your input is invalid." << endl; 
		return GameBase::prompt(x, y);
	}

}





int GameBase::play() {

	//output the initial board

	print();

	while (1) {
		if (this->turn() == QUIT) {

			cout << count - 1 << " turns has been played." << endl;
			cout << "Player " << player << " decides to quit" << endl;
			return QUIT;
		}
		/*After a valid move is made, check if the player has won.
		If so, print the message showing the player wins and end the game.
		Since we have alternated the turn in turn(), the winner should be the last player.
		*/
		if (this->done()) {
			cout << "Player " << player << " wins" << endl;
			return 0;
		}

		if (this->draw()) {

			cout << "No winner" << endl;
			cout << count << " turns has been played." << endl;
			return DRAW;

		}

	}

}

// using unique_ptr get rid of memroy issue
unique_ptr<GameBase> GameBase::GameType(int argc, char* argv[]){


	if (argc == num_argument) {

		//GameBase* gb;

		//two type of game we have till now.
		if (argv[name_argument] == string("TicTacToe")) {
			unique_ptr<GameBase> gb(new TicTacToe);
			return gb;
		}

		if (argv[name_argument] == string("Gomoku")) {
			unique_ptr<GameBase> gb (new gomoku);
			return gb;
		}

	}
	return 0;
}



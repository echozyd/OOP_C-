// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Header1.h"

using namespace std;


vector<string> parsing(char* filename, vector<string>& output) {
	ifstream ifs;
	ifs.open(filename);
	string val;
	string word;
	if (ifs.is_open()) {
		while (getline(ifs, val)) {
			istringstream iss(val);

			while (iss >> word) {
				output.push_back(word);
			}
		}
	}

	//for (int i = 0; i < output.size; i++) {
	// cout << output[i] << endl;
	return output;
}



void helpful(const string& argv0) {

	cout << "Please run " << argv0 << " like: " <<argv0 <<" xxxxx.txt"  << endl;

}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		helpful(argv[0]);
		return wrong_input;
	}

	char* fn = argv[1];
	vector <string> str;
	str = parsing(fn, str);

	vector <int> ints;

	for (int i = 0; i < str.size(); i++) {
		bool all_digit = true;
		for (int j = 0; j < str[i].length(); j++) {
			if (!isdigit(str[i][j])) {
				all_digit = false;
			}

		}
		if (!all_digit) {
			cout << str[i] << endl;
		}
		else {
			for (int k = 0; k < str[i].length(); k++) {
				ints.push_back(str[i][k] - '0');
			}
		}
	}

	for (int i = 0; i < ints.size(); i++) {
		cout << ints[i] << endl;
	}

	return success;

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
/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "LSCommand.h"
#include "ReadFileVisitor.h"
#include<iostream>
#include <sstream>

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int LSCommand::execute(std::string& CWD, std::string options) {
	AbstractFile* f = fs->openFile(CWD);
	if (f == nullptr) { // err for cannot open such directory
		cout << "failed to open directory" << endl;
		return directorydoesnotexist;
	}
	// check if other options inputted , filter onley -l

	// if we have -l we use the content to open all subfiels and get their meta data
	else {
		if (options != "" && options == "-l") {
			vector<char> contents = f->read();
			stringstream ss;

			for (int i = 0; i < contents.size(); i++) {
				ss << contents[i];
			}

			string subfile;
			while (ss >> subfile)
			{
				AbstractFile* sf = fs->openFile(CWD + "/" + subfile);
				//cout << subfile;
				auto it = subfile.find_last_of(".");
				if (it == string::npos) {
					cout << subfile << "    " << "directory" << "    " << sf->getSize() << endl;
					fs->closeFile(sf);
				}
				else if (subfile.substr(it + 1) == "txt") {
					cout << subfile << "    " << "text" << "    " << sf->getSize() << endl;
					fs->closeFile(sf);
				}
				else {
					cout << subfile << "     " << "image" << "     " << sf->getSize() << endl;
					fs->closeFile(sf);
				}

			}
			fs->closeFile(f);
			return success;
		}
		// if no -l just dispaly content. 
		else if (options == "") {
			ReadFileVisitor reader;
			f->accept(&reader);
			fs->closeFile(f);
			return success;
		}
		else {
			return invalidcommand;
			// some error for ls but not -l
		}
	}

}
void LSCommand::displayInfo() {
	cout << "lists the contents of the current directory" << endl;
	cout << "Usage: ls" << endl;
}
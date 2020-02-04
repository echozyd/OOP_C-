#include "DisplayCommand.h"
#include "ReadFileVisitor.h"
#include "ReadUnformatedFileVisitor.h"
#include<iostream>

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int DisplayCommand::execute(string& CWD, string options) {
	string fullpath;
	string true_options;
	
	// check if there is -d and use different type of visitor
	auto it = options.find(" -d");

	//if no "-d"
	if (it == string::npos) {
		
		fullpath = CWD + "/" + options;
		AbstractFile* f = fs->openFile(fullpath);
		if (f == nullptr) { // failed to opendirectory
			cout << "failed to open directory" << endl;
			return directorydoesnotexist;
		}
		ReadFileVisitor* visit = new ReadFileVisitor();
		f->accept(visit);
		fs->closeFile(f);
		delete visit;
		return success;
	}
	else {
		true_options = options.substr(0, it);
		fullpath = CWD + "/" + true_options;

		AbstractFile* f = fs->openFile(fullpath);
		if (f == nullptr) { // failed to opendirectory
			cout << "failed to open directory" << endl;
			return directorydoesnotexist;
		}
		ReadUnformatedFileVisitor unf_reader;
		f->accept(&unf_reader);
		fs->closeFile(f);
		return success;
	}
}


void DisplayCommand::displayInfo() {
	cout << "Display command opens a file and displays its contents" << endl;
	cout << "Usage: ds <filename> [-d]" << endl;
}
#include "RemoveCommand.h"
#include "DirectoryFile.h"
#include "ProxyFile.h"
#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include <iterator>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}


void RemoveCommand::delete_r(std::string CWD, std::string filetodelte) {
	string fullpath = CWD + "/" + filetodelte;
	AbstractFile* op = fs->openFile(fullpath);

	// check if non-empty directory file

	if (dynamic_cast<DirectoryFile*> (op) != nullptr && op->getSize() > 0) {
		stringstream ss;
		vector<char> contents = op->read();
		for (int i = 0; i < contents.size(); i++) {
			ss << contents[i];
		}

		//get all childs and recursively delete 
		vector<string> childs;
		string token;
		while (ss >> token) {
			childs.push_back(token);
		}

		for (auto it = childs.begin(); it != childs.end(); it++) {
			delete_r(fullpath, *it);
		}

		fs->closeFile(op);
	    fs->deleteFile(fullpath);
		// if we finally cannot delete the directory  cout a message 
		AbstractFile* op_check = fs->openFile(fullpath);
		if (op_check== nullptr) {
			std::cout << "unable to delete non-empty directory";
		}
		fs->closeFile(op_check);
		return;
	}
	else {
		fs->closeFile(op);
		fs->deleteFile(fullpath);
		return;
	}

}

// removes a file from the current working directory
int RemoveCommand::execute(std::string& CWD, std::string options) {
	string fullPath = CWD;
	fullPath += '/';
	string true_options;
	auto it = options.find("-r");

	// if no "-r"
	if (it == string::npos) {
		true_options = options;
		AbstractFile* op = fs->openFile(fullPath + true_options);

		if (op != nullptr) {
			if (dynamic_cast<DirectoryFile*>(op) != nullptr && op->getSize() > 0) {
				// return some error (can not close non-empty directory whtiouth -r)
				std::cout << "unable to delete non-empty directory";
				fs->closeFile(op);
				return AbstractFileSystem::cantdeletenonemptydirectory;
			}
			fs->closeFile(op);
			fs->deleteFile(fullPath + true_options);
			return success;
		}
		else {
			int result = fs->deleteFile(fullPath + true_options);

			if (result == AbstractFileSystem::filedoesnotexist) {
				cout << "File does not exist" << endl;
				return filedoesnotexist;
			}
			if (result == AbstractFileSystem::fileisopen) {
				cout << "File is currently in use" << endl;
				return fileinuse;
			}
		}
	}
	// with -r recursively delete
	else {
		true_options = options.substr(0, it-1);
		AbstractFile* op = fs->openFile(fullPath + true_options);
		if (op != nullptr) {
			if (dynamic_cast<DirectoryFile*>(op) != nullptr && op->getSize() > 0) {
				// return some error (can not close non-empty directory whtiouth -r)
				// try to delete the part that could be deleted 
				fs->closeFile(op);
				delete_r(CWD, true_options);
				return success;
			}

			else {
				fs->closeFile(op);
				fs->deleteFile(fullPath + true_options);
				return success;
			}
		}
		else {
		int result = fs->deleteFile(fullPath+true_options);

		if (result == AbstractFileSystem::filedoesnotexist) {
			cout << "File does not exist" << endl;
			return filedoesnotexist;
		}
		if (result == AbstractFileSystem::fileisopen) {
			cout << "File is currently in use" << endl;
			return fileinuse;
		}
		return success;
		}
		
	}

}




void RemoveCommand::displayInfo() {
	cout << "touch removes a file from the file system and then deletes the file" << endl;
	cout << "Usage: rm <filename>" << endl;
}
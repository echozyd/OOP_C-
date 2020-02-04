#include <iostream>

#include "symCommand.h"
#include "ProxyFile.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "ReadFileVisitor.h"
#include <vector>



symCommand::symCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}




int symCommand::execute(std::string& CWD, std::string options) {
	auto it = options.find_first_of(".");
	if (it == std::string::npos) {
		return AbstractFileSystem::cannotsymdirectory;
	}
	// we cannot set a sym link for dir thus we need to find "."
	// after . 5 index is the directory
	// before . 4 index is the file name 
	else {
		std::string target_dir = options.substr(it + 5, std::string::npos);
		std::string file_to_sym = options.substr(0, it + 4);

		AbstractFile* op = fs->openFile(CWD + "/" + file_to_sym);

		// if target is not already a proxy 
		// make a copy, store it in heap
		// make 2 sym link pointing to it with 2 different constructor
		if (dynamic_cast<ProxyFile*> (op) == nullptr){
			AbstractFile* hidden_file = op->clone();
			fs->closeFile(op);

			ProxyFile* first = new ProxyFile(hidden_file);
			fs->deleteFile(CWD + "/" + file_to_sym);

			fs->addFile(CWD + "/" , first);

			ProxyFile* second = new ProxyFile(first); 
			fs->addFile(target_dir + "/", second);

			return success;
		}
		// if target file is already a proxy, use the copy constructor
		else
		{
			ProxyFile* new_proxy = new ProxyFile(op);

			fs->addFile(target_dir + "/", new_proxy);

			return success;
		}

	}
}





void symCommand::displayInfo() {
	std::cout << "sym makes symbolic link to target file" << std::endl;
	std::cout << "Usage: sym <filename> <target directory>" << std::endl;
}

#include <iostream>

#include "CopyCommand.h"
#include "ProxyFile.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "DirectoryFile.h"
#include "ReadFileVisitor.h"
#include "AbstractFileSystem.h"
#include <vector>



CopyCommand::CopyCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}



int CopyCommand::execute(std::string& CWD, std::string options) {

	// cannot copy a direcotry, thus use "." to find the content we want
	// two part: file name we want to copy and directory we want to put the copy
	auto it = options.find(".");
	
	if (it == std::string::npos) {
		return AbstractFileSystem::cannotcopydirectory;
	}
	else {
		std::string target_dir = options.substr(it + 5, std::string::npos);
		std::string file_to_copy = options.substr(0, it + 4);

		std::string fullpath = CWD + "/" + file_to_copy;
		AbstractFile* op = fs->openFile(CWD + "/" + file_to_copy);
		AbstractFile* new_file = op->clone();

		int ifexist = fs->addFile(target_dir + "/", new_file);
		fs->closeFile(op);

		if (ifexist == success) 
		{ 
			return success; 
		}
		else 
		{
			return AbstractFileSystem::fileexists;
		}
	}

}




void CopyCommand::displayInfo() {
	std::cout << "copy a file from current directory to target directory" << std::endl;
	std::cout << "Usage: cp <filename> <target directory>" << std::endl;
}

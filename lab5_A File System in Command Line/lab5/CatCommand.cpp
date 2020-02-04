#include <iostream>

#include "CatCommand.h"
#include "TextFile.h"
#include "ReadFileVisitor.h"
#include "ReadUnformatedFileVisitor.h"
#include <vector>



CatCommand::CatCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}


int CatCommand::execute(std::string& CWD, std::string options) {
	std::string true_file_name;

	// check if we can find -a and then extract the true file name from the options. 
	auto it = options.find(" -a");
	std::string full_path;
	auto it1 = options.find(".");
	if (it1 == std::string::npos) {
		return cantcatdirctory;
	}
	if (it == std::string::npos) {
		true_file_name = options;
		full_path = CWD + "/" + true_file_name;
		std::cout << full_path << std::endl;
		AbstractFile* op = fs->openFile(full_path);

		std::cout << "Enter data you would like to write to the file, enter :wq to save the file and exit, enter :q to exit withough saving" << std::endl;
		std::string line;
		std::getline(std::cin, line);
		std::vector<char> to_write;
		while (line != ":wq" && line != ":q") {
			for (auto it = line.begin(); it != line.end(); it++) {
				to_write.push_back(*it);
			}
			// each new line in cmd line, also a new line in file and txt only 
			if (true_file_name.substr(true_file_name.size() - 3, true_file_name.size() - 1) == "txt") {
				to_write.push_back('\n');
			}
			std::getline(std::cin, line);
		}

		if (line == ":wq") {
			op->write(to_write);
			fs->closeFile(op);
			return success;
		}
		else if (line == ":q") {
			// do nothing
			fs->closeFile(op);
			return success;
		}

	}
	else {
		true_file_name = options.substr(0, it);
		full_path = CWD + "/" + true_file_name;
		std::cout << full_path << std::endl;
		//print unformateted contents
		ReadUnformatedFileVisitor* visit = new ReadUnformatedFileVisitor();
		AbstractFile* op = fs->openFile(full_path);
		op->accept(visit);
		delete visit;

		std::cout << "Enetr data you would like to add to the file, enter :wq to save the file and exit, enter :q to exit withough saving" << std::endl;
		std::string line;
		std::getline(std::cin, line);
		std::vector<char> to_append;

		// need a new line  when append 
		while (line != ":wq" && line != ":q") {
			for (auto it = line.begin(); it != line.end(); it++) {
				to_append.push_back(*it);
			}
			// each new line in cmd line, make a new line in file, and txt only 
			if (true_file_name.substr(true_file_name.size() - 3, true_file_name.size() - 1) == "txt") {
				to_append.push_back('\n');
			}
			std::getline(std::cin, line);
		}

		if (line == ":wq") {
			op->append(to_append);
			fs->closeFile(op);
			return success;
		}
		else if (line == ":q") {
			// do nothing
			fs->closeFile(op);
			return success;
		}
	}

}



void CatCommand::displayInfo() {
	std::cout << "cat write or append contents to target file" << std::endl;
	std::cout << "Usage: cat <filename>" << "with option -a for append and nonting for write" << std::endl;
}

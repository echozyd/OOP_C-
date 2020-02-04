#include "ReadUnformatedFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "DirectoryFile.h"
#include<iostream>
#include<vector>
using namespace std;

// text is the same 
void ReadUnformatedFileVisitor::visit(TextFile* file) {
	vector<char> contents = file->read();
	for (size_t i = 0; i < contents.size(); ++i) {
		cout << contents[i];
	}
	cout << endl;
}


// for image we skipped all the "\n" but does not print the size of dimension
void ReadUnformatedFileVisitor::visit(ImageFile* file) {
	vector<char> contents = file->read();
	// compiler warning here is fine. I want to be able to be negative
	for (size_t i = 0; i < contents.size(); ++i) {
		cout << contents[i];
	}
	cout << endl;
}


// Directory is the same 
void ReadUnformatedFileVisitor::visit(DirectoryFile* file) {
	vector<char> contents = file->read();
	for (size_t i = 0; i < contents.size(); ++i) {
		cout << contents[i];
	}
	cout << endl;
}
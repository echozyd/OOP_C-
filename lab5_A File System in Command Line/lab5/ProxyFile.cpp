#include<iostream>

#include "proxyFile.h"
#include "HierarchicalFileSystem.h"



ProxyFile::ProxyFile() {};


// constructor from an actual file 
ProxyFile::ProxyFile(AbstractFile* file) {
	this->content = file;
	this->parent = nullptr;
	this->link_count = new  unsigned int(1);

}

// constructor from a proxy
ProxyFile::ProxyFile(ProxyFile* proxy) {
	this->content = proxy->content;
	this->link_count = proxy->link_count;
	*(this->link_count) += 1;
}

// if the link count  >1 after delete it we still need to keep track of the hidden file in heap
// if count =1 , delete the hidden file and count, try not memory leak
ProxyFile::~ProxyFile() {
	if (*(this->link_count) > 1) {
		*(this->link_count) -= 1;
	}
	else {
		delete this->content;
		delete this->link_count;
	}
}

// interface implmentation just call the hidden file 
std::vector<char> ProxyFile::read() {
	return this->content->read();
}

int ProxyFile::write(std::vector<char> things) {
	return this->content->write(things);
}


int ProxyFile::append(std::vector<char> things) {
	return this->content->write(things);
}

unsigned int ProxyFile::getSize() {
	return this->content->getSize();
}

std::string ProxyFile::getName() {
	return this->content->getName();
}

void ProxyFile::accept(AbstractFileVisitor* visitor) {
	this->content->accept(visitor);
}

// proxy is not a compsite file type
int ProxyFile::addChild(AbstractFile*) {
	return notacomposite;
}

int ProxyFile::removeChild(std::string name) {
	return notacomposite;
}
// proxy does not have a child 
AbstractFile* ProxyFile::getChild(std::string name) {
	return nullptr;
}

AbstractFile* ProxyFile::getParent() {
	return parent;
}

void ProxyFile::setParent(AbstractFile* p) {
	parent = p;
}


// prototype
// we need to copy the proxy, thus also make a protoype pattern here 
AbstractFile* ProxyFile::clone() {
	return new ProxyFile(this);
}



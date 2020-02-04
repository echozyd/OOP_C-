#pragma once

#include "AbstractFile.h"



class ProxyFile : public AbstractFile {
public:
	//interface from absfile
	virtual std::vector<char> read();
	virtual int write(std::vector<char>); // re-writes file
	virtual int append(std::vector<char>); // appends to current contents
	virtual unsigned int getSize();
	virtual std::string getName();

	virtual void accept(AbstractFileVisitor*);

	//prototype 
	virtual AbstractFile* clone();

	// own
	ProxyFile();
	ProxyFile(AbstractFile* file);
	ProxyFile(ProxyFile* proxy);
	~ProxyFile();
	void request();

private:
	AbstractFile* parent;
	unsigned int * link_count;
	AbstractFile* content;
	ProxyFile* before;
	ProxyFile* after;

protected:


	// composite pattern functions, should only be used by file system objects or command objects which should be friended
	virtual int addChild(AbstractFile*);
	virtual int removeChild(std::string name);
	virtual void setParent(AbstractFile*);
	virtual AbstractFile* getChild(std::string name);
	virtual AbstractFile* getParent();


};

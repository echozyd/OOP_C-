#pragma once
#include "AbstractCommand.h"


class symCommand : public AbstractCommand {
public:
	enum returnvalues {
		cantcatdirctory
	};
    symCommand(AbstractFileSystem* filesys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~symCommand() = default;
private:
	AbstractFileSystem* fs;


};

#pragma once
#include "AbstractFileVisitor.h"

class ReadUnformatedFileVisitor : public AbstractFileVisitor {
public:
	virtual void visit(TextFile*) override;
	virtual void visit(ImageFile*) override;
	virtual void visit(DirectoryFile*) override;
};
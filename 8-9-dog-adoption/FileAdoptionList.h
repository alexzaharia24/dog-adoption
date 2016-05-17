#pragma once
#include "AdoptionList.h"

class FileAdoptionList: public AdoptionList {
protected:
	string fname;
public:
	FileAdoptionList();
	virtual ~FileAdoptionList() {}

	void setFileName(const std::string& fname);
	virtual void writeToFile(string fname) = 0;
	virtual void displayAdoptionList(string prog) const = 0;
};
#pragma once
#include "FileAdoptionList.h"

class HTMLAdoptionList: public FileAdoptionList {
public:
	void writeToFile(string fname) override;
	void displayAdoptionList(string prog) const override;
};

#pragma once
#include "FileAdoptionList.h"

class CSVAdoptionList : public FileAdoptionList {
public:	
	void writeToFile(string fname) override;
	void displayAdoptionList() const override;
};


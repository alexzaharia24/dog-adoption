#include <fstream>
#include <Windows.h>
#include "CSVAdoptionList.h"
#include "RepositoryExceptions.h"

void CSVAdoptionList::writeToFile(string fname) {
	ofstream fout;
	try {
		fout.open(fname);
	}
	catch (...) {
		throw FileException("Cannot open CSV file to write.");
	}
	this->setFileName(fname);
	for (auto d : this->adopted) {
		fout << d.getBreed() << ',' << d.getName() << ',' << d.getAge() << ',' << d.getPhoto() << '\n';
	}
	fout.close();
}

void CSVAdoptionList::displayAdoptionList(string prog) const
{
	string aux = "\"" + this->fname + "\"";
	if (prog == "2") {
		ShellExecute(NULL, NULL, "excel.exe", aux.c_str(), NULL, SW_SHOWMINIMIZED);
	}
	else {
		ShellExecute(NULL, NULL, "notepad.exe", aux.c_str(), NULL, SW_SHOWMINIMIZED);
	}
	
}


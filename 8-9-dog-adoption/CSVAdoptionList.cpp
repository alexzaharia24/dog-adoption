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

void CSVAdoptionList::displayAdoptionList() const
{
	string aux = "\"" + this->fname + "\"";
	ShellExecute(NULL, NULL, "", aux.c_str(), NULL, SW_SHOWMINIMIZED);
}


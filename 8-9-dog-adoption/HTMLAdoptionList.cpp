#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"
#include "HTMLAdoptionList.h"

void HTMLAdoptionList::writeToFile(string fname) {
	ofstream fout;
	string html;
	try {
		fout.open(fname);
	}
	catch (...) {
		throw FileException("Cannot open HTML file to write.");
	}
	this->setFileName(fname);
	/* Writing the HTML code */
	fout << "<!Doctype HTML>" << endl;
	fout << "<html>" << endl;
		fout << "<head>" << endl 
				<< "<title> Adoption List </title>" << endl 
		  	 << "</head>" << endl;
	fout << "<body> <table border='1'>" << endl;
	fout << "<tr>" << endl 
			<< "<td> Breed </td>" << endl 
			<< "<td> Name </td>" << endl 
			<< "<td> Age </td>" << endl 
			<< "<td> Photo </td>" << endl 
		 << "</tr>" << endl;

		for (auto d : this->adopted) {
			fout << "<tr>" << endl
					<< "<td> " << d.getBreed() << " </td>" << endl
					<< "<td> " << d.getName() << " </td>" << endl 
					<< "<td> " << d.getAge() << " </td>" << endl 
					<< "<td> " << d.getPhoto() << " </td>" << endl
				 << "</tr>" << endl;
		}
			fout << "</table>" << endl;
		fout << "</body>" << endl;
	fout << "</html>" << endl;
	fout.close();
}

void HTMLAdoptionList::displayAdoptionList() const {
	ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Mozilla Firefox\\firefox.exe", this->fname.c_str(), NULL, SW_SHOWMAXIMIZED);
}

#include "FileAdoptionList.h"

FileAdoptionList::FileAdoptionList() : AdoptionList{} {}

void FileAdoptionList::setFileName(const std::string & fname) {
	this->fname = fname;
}


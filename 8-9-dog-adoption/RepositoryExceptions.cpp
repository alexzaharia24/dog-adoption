#include "RepositoryExceptions.h"
using namespace std;

FileException::FileException(const string& msg) {
	this->message = msg;
}
const char* FileException::what() {
	return message.c_str();
}

//Watch out for errors here.
RepositoryException::RepositoryException() {
	this->message = "";
}
RepositoryException::RepositoryException(const string& msg) {
	this->message = msg;
}
const char* RepositoryException::what() {
	return message.c_str();
}

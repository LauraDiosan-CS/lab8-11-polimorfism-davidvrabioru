#include "user.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include<sstream>
using namespace std;

user::user() {
	//cout << "const implicit";
	this->name = NULL;
	
	this->status = NULL;

}
user::user(const char* name, const  char* status) {
	//cout << "constructor with param" << endl;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);

}

user::user(const user& a) {
	//cout << "copy constructor" << endl;
	this->name = new char[strlen(a.name) + 1];
	strcpy_s(this->name, strlen(a.name) + 1, a.name);
	
	this->status = new char[strlen(a.status) + 1];
	strcpy_s(this->status, strlen(a.status) + 1, a.status);

}
//CONSTRUCTOR DE CONVERSIE
user::user(string linie) {

	std::istringstream iss(linie);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2 >> tok3;
	name = new char[tok1.length() + 1];
	strcpy_s(name, tok1.length() + 1, tok1.c_str());
	
	status = new char[tok3.length() + 1];
	strcpy_s(status, tok3.length() + 1, tok3.c_str());
}

user::~user() {
	//cout << "Destructor";
	if (this->name) {
		delete[] this->name;
		this->name = NULL;
	}
	
	if (this->status) {
		delete[] this->status;
		this->status = NULL;
	}

}
char* user::getName() {
	return this->name;
}

char* user::getStatus() {
	return this->status;
}

void user::setName(const char* name) {
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];

	strcpy_s(this->name, strlen(name) + 1, name);


}



void user::setStatus(const char* status) {
	if (this->status) {
		delete[] this->status;
	}
	this->status = new char[strlen(status) + 1];

	strcpy_s(this->status, strlen(status) + 1, status);


}

user& user::operator=(const user& a) {
	this->setName(a.name);
	
	this->setStatus(a.status);

	return *this;
}

bool user::operator==(const user& a) {
	return (strcmp(this->name, a.name) == 0)  && (strcmp(this->status, a.status) == 0);
}
ostream& operator<<(ostream& os, const user& a)
{
	os << a.name<< " " << a.status;
	return os;
}
istream& operator>>(istream& is, user& a)
{
	cout << "Dati numele: ";
	char* nume = new char[10];
	is >> nume;
	cout << "Dati parola:";
	char* status = new char[10];
	is >> status;
	a.setName(nume);
	a.setStatus(status);
	delete[] nume;
	delete[] status;
	return is;
}
#include "Mancare.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include<sstream>
#include <vector>
using namespace std;

Mancare::Mancare() {
	//cout << "const implicit";
	this->name = NULL;
	this->adress = "";
	this->price = 0.0;
	this->cnt = 0;
	

}
Mancare::Mancare(const char* name,string adress, vector<string> list,float price ) {
	//cout << "constructor with param" << endl;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->price = price;
	this->adress = adress;
	for (int i = 0; i < list.size(); i++)
		this->list.push_back(list[i]);


}

Mancare::Mancare(const Mancare& a) {
	//cout << "copy constructor" << endl;

	this->name = new char[strlen(a.name) + 1];
	strcpy_s(this->name, strlen(a.name) + 1, a.name);

	this->price = a.price;

	this->adress = a.adress;

	for (int i = 0; i < a.list.size(); i++)
		this->list.push_back(a.list[i]);
	

}


Mancare::~Mancare() {
	//cout << "Destructor";
	if (this->name) {
		delete[] this->name;
		this->name = NULL;
	}
	adress = "";
	price = 0;

}


// geter
char* Mancare::getName() {
	return this->name;
}
float Mancare::getPrice() {
	return this->price;
}
string Mancare::getAdress() {
	return this->adress;
}

vector<string> Mancare::getList()
{
	return this->list;
}


//seter
void Mancare::setName(const char* name) {
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];

	strcpy_s(this->name, strlen(name) + 1, name);


}
void Mancare::setPrice(float price) {
	this->price = price;
}


void Mancare::setAdress(string adress) {
	this->adress = adress;
}

void Mancare::setList(string elem, int poz)
{
	list[poz] = elem;
}



Mancare& Mancare::operator=(const Mancare& a) {
	this->setName(a.name);
	this->setPrice(a.price);
	this->setAdress(a.adress);

	list.clear();
	for (int i = 0; i < a.list.size(); i++)
		this->list.push_back(a.list[i]);


	return *this;
}

bool Mancare::operator==(const Mancare& a) {
	return (strcmp(this->name, a.name) == 0) && (this->price == a.price) && (this->adress== a.adress) && (a.list.size() == list.size());
}
ostream& operator<<(ostream& os, const Mancare& a)
{
	os << a.name << " " << a.price << " " << a.adress<<endl<<"lista: "<<endl;
	for (int i = 0; i < a.list.size(); i++)
		os << a.list[i] << endl;
	return os;
}

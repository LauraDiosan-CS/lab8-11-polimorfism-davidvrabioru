
#pragma once
#include"Comanda.h"
#include<string>
#include<iostream>
#include <vector>
using namespace std;
#ifndef MANCARE_H
#define MANCARE_H
class Mancare : public Comanda {
private:
	/*char* producer;
	char* model;
	int units;*/
	vector<char*> lista;
public:
	Mancare();
	Mancare(const char*, const char*, int, vector<char*>);
	Mancare(const Mancare&);
	Mancare(string);//conversion
	~Mancare();
	Comanda* clone();
	/*char* getProducer();
	char* getModel();
	int getUnits();*/
	vector<char*> getlista();
	/*void setProducer(const char*);
	void setModel(const char*);
	void setUnits(int);*/
	void setlista(vector<char*>);

	Mancare& operator=(const Mancare&);
	/*bool operator ==(const Mancare&);
	bool operator<(const Mancare&);*/

	friend ostream& operator <<(ostream& os, Mancare e);
	friend istream& operator >> (istream& is, Mancare& e);

};
#endif
#pragma once
#include"Comanda.h"
#include<string>
#include<iostream>
#include <vector>
using namespace std;
#ifndef SHOPPING_H
#define SHOPPING_H
class Shopping : public Comanda {
private:
	/*char* producer;
	char* model;
	int units;*/
	vector<char*> lista;
	char* magazin;
public:
	Shopping();
	Shopping(const char*, const char*, int, vector<char*>, const char*);
	Shopping(const Shopping&);
	Shopping(string);//conversion
	~Shopping();
	Comanda* clone();
	/*char* getProducer();
	char* getModel();
	int getUnits();*/
	vector<char*> getlista();
	char* getMagazin();
	/*void setProducer(const char*);
	void setModel(const char*);
	void setUnits(int);*/
	void setlista(vector<char*>);
	void setMagazin(const char*);
	Shopping& operator=(const Shopping&);
	/*bool operator ==(const Shopping&);
	bool operator<(const Shopping&);*/

	friend ostream& operator <<(ostream& os, Shopping e);
	friend istream& operator >> (istream& is, Shopping& e);

};
#endif
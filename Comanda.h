#pragma once
#include<string>
#include<iostream>
using namespace std;

#ifndef COMANDA_H
#define COMANDA_H
class Comanda {
protected:
	char* numeClient;
	char* adresaClient;
	int pret;
public:
	Comanda();
	Comanda(const char*, const char*, int);
	Comanda(const Comanda&);
	virtual Comanda& operator= (const Comanda&);
	Comanda(string); //conversion
	virtual ~Comanda();
	virtual Comanda* clone();
	char* getnumeClient();
	char* getadresaClient();
	int getpret();
	void setnumeClient(const char*);
	void setadresaClient(const char*);
	void setpret(int);

	virtual bool operator ==(const Comanda&);
	virtual bool operator <(const Comanda&);
	friend ostream& operator <<(ostream& os, Comanda e);
	friend istream& operator >>(istream& is, Comanda& e);
};
#endif
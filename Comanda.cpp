#include"Comanda.h"
#include<string.h>
#include <sstream>

Comanda::Comanda() {
	this->numeClient = NULL;
	this->adresaClient = NULL;
	this->pret = 0;
}

Comanda::Comanda(const char* numeClient, const char* adresaClient, int pret) {
	this->pret = pret;
	if (adresaClient) {
		this->adresaClient = new char[strlen(adresaClient) + 1];
		strcpy_s(this->adresaClient, strlen(adresaClient) + 1, adresaClient);
	}
}

Comanda::Comanda(const Comanda& e) {
	if (e.numeClient) {
		this->numeClient = new char[strlen(e.numeClient) + 1];
		strcpy_s(this->numeClient, strlen(e.numeClient) + 1, e.numeClient);
	}
	this->pret = e.pret;
	if (e.adresaClient) {
		this->adresaClient = new char[strlen(e.adresaClient) + 1];
		strcpy_s(this->adresaClient, strlen(e.adresaClient) + 1, e.adresaClient);
	}
}

Comanda::Comanda(string line) {
	std::istringstream iss(line);
	string tok1, tok2, tok3, tok4;
	iss >> tok1 >> tok2 >> tok3;
	this->numeClient = new char[tok1.length() + 1];
	strcpy_s(this->numeClient, tok1.length() + 1, tok1.c_str());
	this->adresaClient = new char[tok2.length() + 1];
	strcpy_s(this->adresaClient, tok2.length() + 1, tok2.c_str());
	this->pret = stoi(tok3);
	//AICI TREBUIE GANDITTT
}
Comanda::~Comanda() {
	if (this->numeClient) {
		delete[] this->numeClient;
		this->numeClient = NULL;
	}
	if (this->adresaClient) {
		delete[] this->adresaClient;
		this->adresaClient = NULL;
	}
}
Comanda* Comanda::clone() {
	Comanda* newComanda = new Comanda();
	newComanda->setnumeClient(this->numeClient);
	newComanda->setadresaClient(this->adresaClient);
	newComanda->setpret(this->pret);
	return newComanda;
}
char* Comanda::getnumeClient() {
	return this->numeClient;
}

char* Comanda::getadresaClient() {
	return this->adresaClient;
}

int Comanda::getpret() {
	return this->pret;
}


void Comanda::setnumeClient(const char* numeClient) {
	if (this->numeClient) {
		delete[] this->numeClient;
	}
	this->numeClient = new char[strlen(numeClient) + 1];
	strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
}

void Comanda::setadresaClient(const char* adresaClient) {
	if (this->adresaClient) {
		delete[] this->adresaClient;
	}
	this->adresaClient = new char[strlen(adresaClient) + 1];
	strcpy_s(this->adresaClient, strlen(adresaClient) + 1, adresaClient);
}

void Comanda::setpret(int pret) {
	this->pret = pret;
}
Comanda& Comanda::operator =(const Comanda& e) {
	if (this == &e) return *this; //in case of self assignment
	if (e.numeClient) {
		if (this->numeClient)delete[]this->numeClient;
		this->numeClient = new char[strlen(e.numeClient) + 1];
		strcpy_s(this->numeClient, strlen(e.numeClient) + 1, e.numeClient);
	}
	if (e.adresaClient) {
		if (this->adresaClient)delete[]this->adresaClient;
		this->adresaClient = new char[strlen(e.adresaClient) + 1];
		strcpy_s(this->adresaClient, strlen(e.adresaClient) + 1, e.adresaClient);
	}
	this->pret = e.pret;
	return *this;
}

bool Comanda::operator==(const Comanda& e) {
	if (this->numeClient and e.numeClient and this->adresaClient and e.adresaClient) {
		return (strcmp(this->numeClient, e.numeClient) == 0) and (strcmp(this->adresaClient, e.adresaClient) == 0) and (this->pret == e.pret);
	}
	return false;
}

bool Comanda::operator<(const Comanda& e) {
	return (strcmp(this->numeClient, e.numeClient) < 0);
}
ostream& operator<<(ostream& os, Comanda e) {
	os << e.numeClient << " " << e.adresaClient << " " << e.pret << endl;
	return os;
}

istream& operator >>(istream& is, Comanda& e) {
	cout << "Give the numeClient: ";
	char* numeClient = new char[10];
	is >> numeClient;
	cout << "Give the adresaClient: ";
	char* adresaClient = new char[10];
	is >> adresaClient;
	cout << "Give the pret: ";
	int pret;
	is >> pret;
	int ok = 0;


	e.setnumeClient(numeClient);
	e.setadresaClient(adresaClient);
	e.setpret(pret);
	delete[] numeClient;
	delete[] adresaClient;
	return is;
}
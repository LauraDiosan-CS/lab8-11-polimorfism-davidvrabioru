
#include "Mancare.h"
#include<string.h>
#include<sstream>

Mancare::Mancare() {
	//this->numeClient = NULL;
	//this->adresaClient = NULL;
	//this->pret = 0;
	//this->lista = {};
}
Mancare::Mancare(const char* numeClient, const char* adresaClient, int pret, vector<char*> lista) :Comanda(numeClient, adresaClient, pret) {
	/*if (numeClient) {
		this->numeClient = new char[strlen(numeClient) + 1];
		strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
	}
	this->pret = pret;
	if (adresaClient) {
		this->adresaClient = new char[strlen(adresaClient) + 1];
		strcpy_s(this->adresaClient, strlen(adresaClient) + 1, adresaClient);
	}*/
	this->lista = lista;
}

Mancare::Mancare(const Mancare& e) :Comanda(e) {
	/*if (e.numeClient) {
		this->numeClient = new char[strlen(e.numeClient) + 1];
		strcpy_s(this->numeClient, strlen(e.numeClient) + 1, e.numeClient);
	}
	this->pret = e.pret;
	if (e.adresaClient) {
		this->adresaClient = new char[strlen(e.adresaClient) + 1];
		strcpy_s(this->adresaClient, strlen(e.adresaClient) + 1, e.adresaClient);
	}*/
	this->lista = e.lista;
}

Mancare::Mancare(string line) {
	std::istringstream iss(line);
	string tok1, tok2, tok3, tok4;
	iss >> tok1 >> tok2 >> tok3 >> tok4;
	this->numeClient = new char[tok1.length() + 1];
	strcpy_s(this->numeClient, tok1.length() + 1, tok1.c_str());
	this->adresaClient = new char[tok2.length() + 1];
	strcpy_s(this->adresaClient, tok2.length() + 1, tok2.c_str());
	this->pret = stoi(tok3);


	std::string delim = "-";
	std::string token;
	size_t prev = 0, pos = 0;
	do
	{
		pos = tok4.find(delim, prev);
		if (pos == string::npos) pos = tok4.length();
		{string token = tok4.substr(prev, pos - prev);
		}
		if (!token.empty()) {
			char* c = new char[sizeof(token) + 1];
			for (int i = 0; i < sizeof(token); i++) {
				c[i] = token[i];
			}
			if (c) { this->lista.push_back(c); }
			delete[] c;
		}
		prev = pos + delim.length();
	} while (pos < tok4.length() && prev < tok4.length());
}

Comanda* Mancare::clone() {
	Mancare* newComanda = new Mancare();
	newComanda->setnumeClient(this->numeClient);
	newComanda->setadresaClient(this->adresaClient);
	newComanda->setpret(this->pret);
	newComanda->setlista(this->lista);
	return newComanda;
}
//char* Mancare::getnumeClient() {
//	return this->numeClient;
//}
//
//char* Mancare::getadresaClient() {
//	return this->adresaClient;
//}
//
//int Mancare::getpret() {
//	return this->pret;
//}

vector<char*> Mancare::getlista() {
	return this->lista;
}
//void Mancare::setnumeClient(const char* numeClient) {
//	if (this->numeClient) {
//		delete[] this->numeClient;
//	}
//	this->numeClient = new char[strlen(numeClient) + 1];
//	strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
//}
//
//void Mancare::setadresaClient(const char* adresaClient) {
//	if (this->adresaClient) {
//		delete[] this->adresaClient;
//	}
//	this->adresaClient = new char[strlen(adresaClient) + 1];
//	strcpy_s(this->adresaClient, strlen(adresaClient) + 1, adresaClient);
//}
//
//void Mancare::setpret(int pret) {
//	this->pret = pret;
//}

void Mancare::setlista(vector<char*> lista) {
	this->lista = lista;
}


Mancare::~Mancare() {
	if (this->numeClient) {
		delete[] this->numeClient;
		this->numeClient = NULL;
	}
	if (this->adresaClient) {
		delete[] this->adresaClient;
		this->adresaClient = NULL;
	}
}


Mancare& Mancare::operator =(const Mancare& e) {
	if (this == &e) return *this;
	if (e.numeClient) {
		if (this->numeClient) delete[] this->numeClient;
		this->numeClient = new char[strlen(e.numeClient) + 1];
		strcpy_s(this->numeClient, strlen(e.numeClient) + 1, e.numeClient);
	}
	if (e.adresaClient) {
		if (this->adresaClient)delete[]this->adresaClient;
		this->adresaClient = new char[strlen(e.adresaClient) + 1];
		strcpy_s(this->adresaClient, strlen(e.adresaClient) + 1, e.adresaClient);
	}
	this->pret = e.pret;
	this->lista = e.lista;

	
}

//bool Mancare::operator ==(const Mancare& e) {
//	if (this->numeClient and e.numeClient and this->adresaClient and e.adresaClient) {
//		return (strcmp(this->numeClient, e.numeClient) == 0) and (strcmp(this->adresaClient, e.adresaClient) == 0) and (this->pret == e.pret);
//	}
//	return false;
//}
//
//bool Mancare::operator<(const Mancare& e) {
//	return (strcmp(this->numeClient, e.numeClient) < 0);
//}

ostream& operator<<(ostream& os, Mancare e) {
	os << e.numeClient << " " << e.adresaClient << " " << e.pret << " " << endl;

	for (int i = 0; i < e.lista.size() - 1; i++)
		os << e.lista[i] << "-";
	os << e.lista[e.lista.size() - 1] << endl;
	return os;

	
}

istream& operator>>(istream& is, Mancare& e) {
	cout << "Dati numeClient: ";
	char* numeClient = new char[10];
	is >> numeClient;
	cout << "Dati adresaClient: ";
	char* adresaClient = new char[10];
	is >> adresaClient;
	cout << "Dati pret: ";
	int pret;
	is >> pret;
	cout << "Dati lista: ";
	vector<char*> lista;
	char* op = new char[10];
	is >> op;
	while (strcmp(op, "x") != 0)
		lista.push_back(op);


	e.setnumeClient(numeClient);
	e.setadresaClient(adresaClient);
	e.setpret(pret);
	e.setlista(lista);
	delete[] numeClient;
	delete[] adresaClient;
	delete[] op;
	return is;
}

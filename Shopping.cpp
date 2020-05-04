#include "Shopping.h"
#include<string.h>
#include<sstream>

Shopping::Shopping() {
	//this->numeClient = NULL;
	//this->adresaClient = NULL;
	//this->pret = 0;
	//this->lista = {};
	this->magazin = NULL;
}
Shopping::Shopping(const char* numeClient, const char* adresaClient, int pret, vector<char*> lista, const char* magazin) :Comanda(numeClient, adresaClient, pret) {
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

	if (magazin) {
		this->magazin = new char[strlen(magazin) + 1];
		strcpy_s(this->magazin, strlen(magazin) + 1, magazin);
	}
}

Shopping::Shopping(const Shopping& e) :Comanda(e) {
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
	if (e.magazin) {
		this->magazin = new char[strlen(e.magazin) + 1];
		strcpy_s(this->magazin, strlen(e.magazin) + 1, e.magazin);
	}

}

Shopping::Shopping(string line) {
	std::istringstream iss(line);
	string tok1, tok2, tok3, tok4, tok5;
	iss >> tok1 >> tok2 >> tok3 >> tok4 >> tok5;
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


	this->magazin = new char[tok5.length() + 1];
	strcpy_s(this->magazin, tok5.length() + 1, tok5.c_str());
}
Shopping::~Shopping() {
	if (this->numeClient) {
		delete[] this->numeClient;
		this->numeClient = NULL;
	}
	if (this->adresaClient) {
		delete[] this->adresaClient;
		this->adresaClient = NULL;
	}

	if (this->magazin) {
		delete[] this->magazin;
		this->magazin = NULL;
	}

}
Comanda* Shopping::clone() {
	Shopping* newComanda = new Shopping();
	newComanda->setnumeClient(this->numeClient);
	newComanda->setadresaClient(this->adresaClient);
	newComanda->setpret(this->pret);
	newComanda->setlista(this->lista);
	newComanda->setMagazin(this->magazin);
	return newComanda;
}
//char* Shopping::getnumeClient() {
//	return this->numeClient;
//}
//
//char* Shopping::getadresaClient() {
//	return this->adresaClient;
//}
//
//int Shopping::getpret() {
//	return this->pret;
//}

vector<char*> Shopping::getlista() {
	return this->lista;
}

char* Shopping::getMagazin() {
	return this->magazin;
}

//void Shopping::setnumeClient(const char* numeClient) {
//	if (this->numeClient) {
//		delete[] this->numeClient;
//	}
//	this->numeClient = new char[strlen(numeClient) + 1];
//	strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
//}
//
//void Shopping::setadresaClient(const char* adresaClient) {
//	if (this->adresaClient) {
//		delete[] this->adresaClient;
//	}
//	this->adresaClient = new char[strlen(adresaClient) + 1];
//	strcpy_s(this->adresaClient, strlen(adresaClient) + 1, adresaClient);
//}
//
//void Shopping::setpret(int pret) {
//	this->pret = pret;
//}

void Shopping::setlista(vector<char*> lista) {
	this->lista = lista;
}

void Shopping::setMagazin(const char* magazin) {
	if (this->magazin) {
		delete[] this->magazin;
	}
	this->magazin = new char[strlen(magazin) + 1];
	strcpy_s(this->magazin, strlen(magazin) + 1, magazin);
}

Shopping& Shopping::operator =(const Shopping& e) {
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
	this->lista = lista;

	if (e.magazin) {
		if (this->magazin)delete[]this->magazin;
		this->magazin = new char[strlen(e.magazin) + 1];
		strcpy_s(this->magazin, strlen(e.magazin) + 1, e.magazin);
	}

}

//bool Shopping::operator ==(const Shopping& e) {
//	if (this->numeClient and e.numeClient and this->adresaClient and e.adresaClient) {
//		return (strcmp(this->numeClient, e.numeClient) == 0) and (strcmp(this->adresaClient, e.adresaClient) == 0) and (this->pret == e.pret);
//	}
//	return false;
//}
//
//bool Shopping::operator<(const Shopping& e) {
//	return (strcmp(this->numeClient, e.numeClient) < 0);
//}

ostream& operator<<(ostream& os, Shopping e) {
	os << e.numeClient << " " << e.adresaClient << " " << e.pret <<" "<<e.magazin<< endl;

	for (int i = 0; i < e.lista.size() - 1; i++)
		os << e.lista[i] << "-";
	os << e.lista[e.lista.size() - 1] << endl;
	return os;
}

istream& operator>>(istream& is, Shopping& e) {
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



	cout << "Dati nume magazin: ";
	char* magazin = new char[14];
	is >> magazin;
	e.setnumeClient(numeClient);
	e.setadresaClient(adresaClient);
	e.setpret(pret);
	e.setlista(lista);
	e.setMagazin(magazin);
	delete[] numeClient;
	delete[] adresaClient;
	delete[] op;
	delete[] magazin;
	return is;
}
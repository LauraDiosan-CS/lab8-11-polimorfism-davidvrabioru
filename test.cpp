#include "test.h"
#include "assert.h"
#include<iostream>
#include<string.h>
#include <vector>
#include <list>
using namespace std;
Tests::Tests() {
}

void Tests::TestMancare() {
	vector<char*> v;
	Mancare e1("and", "ipotesti", 1, v);
	Mancare e2(e1);
	Mancare e3;
	Mancare e4("eee aaa 1 orange-cosmote");
	assert(strcmp(e4.getlista()[0], "orange") == 0);
	assert(e3.getadresaClient() == NULL);
	assert(e3.getnumeClient() == NULL);
	assert(e3.getpret() == 0);
	e3 = e2;
	assert(strcmp(e3.getnumeClient(), "andrei") == 0);
	assert(strcmp(e2.getadresaClient(), "ipotesti") == 0);
	assert(e1 == e2);
	e2.setadresaClient("suceava");
	assert(strcmp(e2.getadresaClient(), "suceava") == 0);
	cout << "TEst 1 Succes!" << endl;
}

void Tests::TestCumparaturi() {
	vector<char*> v;
	Shopping e1("andrei", "ipotesti", 1, v, "Real");
	Shopping e2(e1);
	Shopping e3;
	Shopping e4("a b 1 sss-sss r");
	assert(e4.getpret() == 1);
	assert(e3.getadresaClient() == NULL);
	assert(e3.getnumeClient() == NULL);
	assert(e3.getpret() == 0);
	e3 = e2;
	assert(strcmp(e3.getadresaClient(), "ipotesti") == 0);
	assert(strcmp(e2.getadresaClient(), "ipotesti") == 0);
	assert(e1 == e2);
	e2.setadresaClient("suceava");
	assert(strcmp(e2.getadresaClient(), "suceava") == 0);
}
void Tests::testRepoTemplate() {
	vector<char*> v;
	char* c = new char[10];
	strcpy_s(c, 7, "ssssss");
	v.push_back(c);
	Mancare e1("aaa", "suceava", 1, v);
	Mancare e2("bbb", "suceava", 1, v);
	Mancare e3("ccc", "suceava", 1, v);
	Mancare e4("ddd", "suceava", 1, v);
	RepositoryTemplate<Mancare> rep;
	rep.addElem(e1);
	rep.addElem(e2);
	rep.addElem(e3);
	rep.addElem(e4);
	assert(rep.getSize() == 4);
	assert(rep.getAll().front() == e1);
	assert(rep.getAll().back() == e4);
	assert(rep.getItemFromPos(0) == e1);
	Mancare elemArray[] = { e1,e2,e3,e4 };
	list <Mancare> elem;
	elem = rep.getAll();
	list <Mancare>::iterator it;
	int i = 0;
	for (it = elem.begin(); it != elem.end() and i < 4; ++it)
	{
		assert(*it == elemArray[i]);
		i++;

	}
	Mancare e0("eee", "MS 77 SSA", 1, v);
	Mancare e01("bbb", "aaa", 1, v);
	assert(rep.findElem(e4) == 3);
	assert(rep.findElem(e0) == -1);
	rep.deleteElem(e3);
	assert(rep.findElem(e3) == -1);
	assert(rep.getSize() == 3);
	Mancare e("bbb", "aaa", 1, v);
	rep.updateElem(e1, e);
	assert(rep.getItemFromPos(0) == e01);
}

void Tests::testRepoFile() {
	RepositoryFile<Shopping> repof("Tests.txt", "Tests.csv");
	vector<char*> v;
	char* c = new char[10];
	strcpy_s(c, 7, "orange");
	v.push_back(c);

	assert(repof.getSize() == 0);
	repof.loadFromFile("Tests.txt");

	assert(repof.getSize() == 4);
	repof.addElem(Shopping("aaa", "bbb",1, v, "real"));
	assert(repof.getSize() == 5);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	assert(repof.findElem(Shopping("aaa", "bbb", 1, v, "real")) == 4);
	assert(repof.findElem(Shopping("sdasd", "aaasdsaa", 1, v,"real")) == -1);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	repof.deleteElem(Shopping("aaa", "bbb", 1, v, "real"));
	assert(repof.getSize() == 4);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	list<Shopping> rez = repof.getAll();
	assert(rez.size() == 4);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	assert(repof.findElem(Shopping("aaa", "bbb", 1, v, "real")) == 0);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	assert(repof.getSize() == 4);

}
void Tests::testRepoFileMancare() {
	RepositoryFile<Mancare> repof("Tests.txt", "Tests.csv");
	vector<char*> v;
	char* c = new char[10];
	strcpy_s(c, 7, "orange");
	v.push_back(c);

	assert(repof.getSize() == 0);
	repof.loadFromFile("Tests.txt");

	assert(repof.getSize() == 4);
	repof.addElem(Mancare("aaa", "bbb", 1, v));
	assert(repof.getSize() == 5);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	assert(repof.findElem(Mancare("aaa", "bbb", 1, v)) == 4);
	assert(repof.findElem(Mancare("abc", "aaa", 1, v)) == -1);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	repof.deleteElem(Mancare("aaa", "bbb", 1, v));
	assert(repof.getSize() == 4);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	list<Mancare> rez = repof.getAll();
	assert(rez.size() == 4);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	repof.updateElem(Mancare("bbb", "aaa", 1, v), Mancare("abc", "aaa", 1, v));
	assert(repof.findElem(Mancare("abc", "aaa", 1, v)) == 0);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	assert(repof.getItemFromPos(0) == Mancare("abc", "aaa", 1, v));
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	assert(repof.getSize() == 4);
}
Tests::~Tests() {
}


#pragma once
#include"Mancare.h"
#include"Shopping.h"
#include "Comanda.h"
#include"Repository.h"
#include"RepositoryFile.h"

class Tests {
private:
	RepositoryFile<Mancare> repof;
	RepositoryTemplate<Shopping> repo;
	//Service serv();
public:
	Tests();
	void TestMancare();
	void TestCumparaturi();
	//void testDomainSerie();
	void testRepoTemplate();
	void testRepoFile();
	void testRepoFileMancare();
	//void testService();
	~Tests();
};
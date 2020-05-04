#include <iostream>
#include "test.h"
using namespace std;


int main()
{
	Tests t1;
	t1.TestMancare();
	cout << "Test Mancare Succes!";
	t1.TestCumparaturi();
	cout << "Test Cumparaturi Succes! ";
	/*
	t1.testRepoFile();
	cout << "Repofile Sopping succes! ";
	t1.testRepoFileMancare();
	cout << "Repofile Mancare Succes! ";
	t1.testRepoTemplate();
	cout << "Template Succes! ";
	*/
	cout << "Is Working !";

	return 0;
}
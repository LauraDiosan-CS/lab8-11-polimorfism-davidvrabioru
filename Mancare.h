#pragma once
#include<ostream>
#include <vector>
using namespace std;

class Mancare {
private:
	char* name;
	string adress;
	vector<string> list;
	float price;
	int cnt = 0;
public:
	Mancare();
	Mancare(const char* name, string adress,vector<string> list, float price);
	Mancare(const Mancare& a);
	~Mancare();

	char* getName();
	string getAdress();
	vector<string> getList();
	float getPrice();
	

	void setName(const char* name);
	void setPrice(float price);
	void setAdress(string adress);
	void setList(string elem, int poz);



	Mancare& operator=(const Mancare& a);
	bool operator==(const Mancare& a);
	friend ostream& operator<<(ostream& os, const Mancare& a);
};
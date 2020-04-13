#pragma once
#include<ostream>
using namespace std;

class user {
private:
	char* name;
	char* status;
public:
	user();
	user(string); //constructor de conversie
	user(const char* name, const char* status);
	user(const user& a);
	~user();
	char* getName();
	char* getStatus();

	void setName(const char* name);
	void setStatus(const char* status);

	user& operator=(const user& a);
	bool operator==(const user& a);

	friend ostream& operator<<(ostream& os, const user& a);
	friend istream& operator>>(istream&, user&);


};
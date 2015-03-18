#ifndef OPERATOR_H
#define OPERATOR_H
#include <string>

using namespace std;

class Operator{
public:
	Operator(){
	}
	~Operator(){}
	virtual bool isOperator(string) = 0;
	virtual char getOpr(string) = 0;
};


class Aritmatika : public Operator{
public:
	Aritmatika();
	~Aritmatika();
	bool isOperator(string);
	char getOpr(string);
	int cekPrecedence(string,string);
	int getPrecedence(string);
};

class Logika : public Operator{
public:
	Logika();
	~Logika();
	bool isOperator(string);
	char getOpr(string);
};

#endif

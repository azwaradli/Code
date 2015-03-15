#ifndef OPERATOR_H
#define OPERATOR_H
#include <string>

using namespace std;

class Operator{
public:
	Operator();
	~Operator();
	virtual bool isOperator(string) = 0;
};


class Aritmatika : public Operator{
public:
	Aritmatika();
	~Aritmatika();
	bool isOperator(string);
	float operator+();
	float operator-();
	float operator*();
	float operator/(float);
};

class Logika : public Operator{
public:
	Logika();
	~Logika();
	bool isOperator(string);
};

#endif

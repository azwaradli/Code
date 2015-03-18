#ifndef KALKULATOR_H
#define KALKULATOR_H
#include "kalkulatorexception.h"
#include "ekspresi.h"
#include "stack.h"
#include "operator.h"
#include "Bilangan_Arab.h"
#include "Bilangan_Romawi.h"
#include "Bilangan_Logika.h"

#include <string>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

class Kalkulator
{
public:
	Kalkulator();
	~Kalkulator();
	float calculate(char,float,float);

	void calculateAll();
	void solveLogicAll();
	void run();
	void setString(string);
	void setHasil(string);
	void save();
	void undo(int);
	void redo(int);
	void show(int n);
	void showall();
	void help();
	string currentDateTime();
	string split(string &str, char chr);

	//getter
	string getModeBilangan();
	string getModeEkspresi();
	void getInfoMode() const;
	void setMode(string);

	//setter
	void setBilArab();
	void setBilRomawi();
	void setExpPrefix();
	void setExpInfix();
	void setExpPostfix();
	void setArit();
	void setLogic();

	//is
	bool isBilArab();
	bool isBilRomawi();
	bool isExpPrefix();
	bool isExpInfix();
	bool isExpPostfix();
	bool isArit();
	bool isLogic();

private:
	int mode[3];
	int counter;
	int top;
	// mode[0] -> mode bilangan -> 0:arab,1:romawi
	// mode[1] -> mode ekspresi -> 0:prefix, 1:infix, 2:postfix
	// mode[2] -> mode operasi  -> 0:aritmatic, 1: logic
	string log[100];
	string hasil[100];
	string input;
};

#endif

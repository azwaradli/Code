#ifndef EKSPRESI_H
#define EKSPRESI_H
#include <string>
#include "stack.h"
#include "operator.h"
#include "Bilangan.h"
#include "kalkulator.h"

using namespace std;

class Ekspresi{
public:
	Ekspresi();
	Ekspresi(string);
	Ekspresi(const Ekspresi&);
	Ekspresi& operator=(const Ekspresi&);
	~Ekspresi();

	//getter
	string getString();
	float getHasil();

	//setter
	void setString(string);
	void setHasil(float);

	//fungsi ekspresi
	string* fromPrefix(int*);
	string* fromInfix(int*);
	string* fromPostfix(int*);
	//virtual void Konversi() = 0

private:
	string s;
	float hasil;
	//Stack S;	kalau return valuenya mau diganti stack
	//string modeEkspresi;
};

/*class Prefix : public Ekspresi{
public:
	Prefix();
	Prefix(const Prefix&);
	Prefix& operator=(const Prefix&);
	~Prefix();
	void Representasi();
	// void Konversi();
};

class Infix : public Ekspresi{
public:
	void Representasi(string);
	// void Konversi();
};

class Postfix : public Ekspresi{
public:
	void Representasi(string);
	// void Konversi();
};*/

#endif

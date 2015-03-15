#ifndef EKSPRESI_H
#define EKSPRESI_H
#include <string>
#include "stack.h"
#include "operator.h"

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
	float fromPrefix();
	float fromInfix();
	float fromPostfix();
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

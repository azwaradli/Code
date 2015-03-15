#ifndef KALKULATOR_H
#define KALKULATOR_H

template <class T>
class Kalkulator
{
public:	
	Kalkulator();
	~Kalkulator();



	T calculate(char,T,T);
	T calculateAll();

private:
	string modeBilangan;	
	string modeEkspresi;
	// pilihan lain: array
};

#endif

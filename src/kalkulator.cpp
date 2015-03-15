#include "kalkulator.h"

using namespace std;

template<class T>
Kalkulator<T>::Kalkulator(){

}

template<class T>
Kalkulator<T>::~Kalkulator(){

}

template<class T>
T Kalkulator<T>::calculate(char opr, T opn1, T opn2){
	if(opr == '+')
		return opn1 + opn2;
	else if(opr == '-')
		return opn1 - opn2;
	else if(opr == '/')
		return opn1 / opn2;
	else if(opr == '*')
		return opn1 * opn2;
	else if(opr == '%')
		return opn1 % opn2;
}

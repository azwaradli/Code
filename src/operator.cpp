#include "operator.h"

Aritmatika::Aritmatika(){

}

Aritmatika::~Aritmatika(){
	
}

bool Aritmatika::isOperator(string s){
	if(s == "+")
		return true;
	else if(s == "-")
		return true;
	else if(s == "*")
		return true;
	else if(s == "/")
		return true;
	else if(s == "%")
		return true;
	else
		return false;
}

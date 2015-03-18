#include "operator.h"
#include <cassert>

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
    else if(s == "(")
        return true;
    else if(s == ")")
        return true;
	else
		return false;
}

char Aritmatika::getOpr(string s){
    if(s == "+")
		return '+';
	else if(s == "-")
		return '-';
	else if(s == "/")
		return '/';
	else if(s == "*")
		return '*';
}



int Aritmatika::getPrecedence(string s){
    if(s == "(")
        return 0;
    else if(s == "*" || s == "/")
        return 2;
    else if(s == "+" || s == "-")
        return 1;
    else
        assert(false);
}

int Aritmatika::cekPrecedence(string opr1, string opr2){
    int a,b;
    a = getPrecedence(opr1);
    b = getPrecedence(opr2);
    if(a < b)
        return 1;   // precendece opr1 lebih besar dari opr2
    else if(a == b)
        return 2;   // precedence opr1 sama dengan opr2
    else if(a > b)
        return 3;   // precedence opr1 lebih besar dari opr2
    else
        assert(false);
}

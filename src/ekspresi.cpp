#include "ekspresi.h"
#include <sstream>

Ekspresi::Ekspresi(){
	s = "";
}

Ekspresi::Ekspresi(string s){
	this->s = s;
}

Ekspresi::Ekspresi(const Ekspresi& E){
	s = E.s;
}

Ekspresi& Ekspresi::operator=(const Ekspresi& E){
	s = E.s;
}

Ekspresi::~Ekspresi(){
	s = "";
}

string Ekspresi::getString(){
	return s;
}

float Ekspresi::getHasil(){
	return hasil;
}

void Ekspresi::setString(string _s){
	s = _s;
}

void Ekspresi::setHasil(float _hasil){
	hasil = _hasil;
}

float Ekspresi::fromPrefix(){
	stringstream ss(s);

	int jumlah = 1;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ' ')
			jumlah++;
	}

	string a[jumlah];	
	Stack temp;
	Aritmatika opr;
	float opn1,opn2,opn;
	for(int i = jumlah - 1; i > 0; i--){
		if(!opr.isOperator(a[i])){
			//a[i] dimasukkan ke fungsi bilangan buat direturn ke float
			temp.Push(opn);
		}
		else{
			temp.Pop(opn1);
			temp.Pop(opn2);
			//opn = hitung(opr,opn1,opn2);
			temp.Push(opn);
		}
	}
	temp.Pop(hasil);
	return hasil;
}

float Ekspresi::fromInfix(){

}

float Ekspresi::fromPostfix(){

}

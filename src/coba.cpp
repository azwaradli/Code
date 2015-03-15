#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include "stack.h"
#include "operator.h"

using namespace std;

int main(){
	string s;
	cout << "masukkan input: ";
	getline(cin,s);	

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
	float hasil;
	for(int i = jumlah - 1; i > 0; i--){
		if(!opr.isOperator(a[i])){
			float hasil = 0;
			for(int i = 0; i < s.size(); i++){
				hasil = hasil + ((float)s[s.size()-1-i] * pow(10.0,i));
				cout << s[s.size()-1-i] * pow(10.0,i) << endl;
			}
			opn = hasil;
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
	cout << hasil;
	
	return 0;
}

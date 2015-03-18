#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "stack.h"
#include "operator.h"
#include "ekspresi.h"
#include <stdlib.h>

using namespace std;

int main()
{
    /*
    string s;
	cout << "masukkan input: ";
	getline(cin,s);*/

    Kalkulator k;
    k.run();
    /*
    Ekspresi e(s);
    string *a;
    int jumlah;
    a = e.fromInfix(&jumlah);
    for(int i = 0; i < jumlah; i++){
        cout << a[i] << " ";
    }*/
    /*
    for(int i = 0; i < 3; i++){
        cout << a[i] << " ";
    }*/
    /*
	stringstream ss(s);
    int size = s.size();
	int jumlah = 1;
	for(int i = 0; i < size; i++){
		if(s[i] == ' ')
			jumlah++;
	}

    string a[jumlah];
    for(int i = 0; i < jumlah; i++){
        ss >> a[i];
    }

    for(int i = 0; i < jumlah; i++){
        cout << a[i] << endl;
    }

	Stack temp;
	Aritmatika arit;
	float opn1,opn2,opn = 0;
	float hasil;
	for(int i = jumlah - 1; i >= 0; i--){
		if(!arit.isOperator(a[i])){
			float hasil = 0;
			size = a[i].size();
			string isi = a[i];
			for(int i = 0; i < size; i++){
                float angka = 0;
                char b = isi[size-1-i];
                angka = arit.toFloat(b);
                cout << isi[i] << " " << angka << endl;
				hasil = hasil + (angka * pow(10.0,i));
				cout << angka * pow(10.0,i) << endl;
			}
			cout << "hasil : " << hasil << endl;
			opn = hasil;
			temp.push(opn);
			cout << endl;
		}
		else{
			temp.pop(opn1);
			temp.pop(opn2);
			char opr = arit.getOpr(a[i]);
			opn = arit.hitung(opr,opn1,opn2);
			cout << "hitung : " << opn << endl;
			temp.push(opn);
		}
	}
	temp.pop(hasil);
	cout << "Hasil hitung: " << hasil;
	*/

	return 0;
}

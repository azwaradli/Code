/**
* @file ekspresi.cpp
**/

#include "ekspresi.h"
#include <sstream>

using namespace std;
/**
* @class Ekspresi
* @author M. Azwar Adli (13514601)
* @version 1.0
*
* @brief Kelas Ekspresi bertugas untuk mengenali dan mengolah ekspresi masukkan
**/

/**
* @brief Konstruktor kelas Ekspresi
**/
Ekspresi::Ekspresi(){
	s = "";
}

/**
* @brief Setter untuk mengubah input.
* @param _s - string input
**/
Ekspresi::Ekspresi(string _s){
	s = _s;
}

/**
* @brief Destruktor kelas saver.
**/
Ekspresi::~Ekspresi(){
	s = "";
}

/**
* @brief Getter untuk mendapatkan string input.
* @return s - string input.
**/
string Ekspresi::getString(){
	return s;
}

/**
* @brief Setter untuk mengubah input.
* @param s - string input
**/
void Ekspresi::setString(string _s){
	s = _s;
}

/**
* @brief Fungsi untuk membaca ekspresi dalam ekspresi prefix
* @return s - array of string yang telah diparse
**/
string* Ekspresi::fromPrefix(int* ekssize){
	stringstream ss(s);
	int jumlah = 1;
	int sz = s.size();
	for(int i = 0; i < sz; i++){
		if(s[i] == ' ')
			jumlah++;
	}
	*ekssize = jumlah;
	string a[jumlah];
	for(int i = 0; i < jumlah; i++){
        ss >> a[i];
	}

	Stack<string> temp;
	Aritmatika arit;
	Kalkulator K;
	string opn1,opn2;
	for(int i = jumlah - 1; i >= 0; i--){
		if(!arit.isOperator(a[i])){
			temp.push(a[i]);
		}
		else{
			temp.pop(opn1);
			temp.pop(opn2);
			string combine = opn1 + " " + opn2 + " " + a[i];
			temp.push(combine);
		}
	}
	string apa;
	temp.pop(apa);
	stringstream st(apa);
	string *s = new string [jumlah];
	for(int i = 0; i < jumlah; i++){
        st >> s[i];
	}

	return s;
}

/**
* @brief Fungsi untuk membaca ekspresi dalam ekspresi infix
* @return s - array of string yang telah diparse
**/
string* Ekspresi::fromInfix(int *ekssize){
    stringstream ss(s);

    int jumlahspasi = 1;
    int jumlahkurung = 0;
	int sz = s.size();
	for(int i = 0; i < sz; i++){
		if(s[i] == ' ')
			jumlahspasi++;
        else if(s[i] == '(' || s[i] == ')')
			jumlahkurung++;
	}
    int jumlahasli = jumlahspasi - jumlahkurung;
    *ekssize = jumlahasli;
	string a[jumlahspasi];
	for(int i = 0; i < jumlahspasi; i++){
        ss >> a[i];
	}

	Stack<string> sOpr;     // stack untuk operator
	Aritmatika arit;
	int counter = 0;
	string *sPost = new string [jumlahasli];

	for(int i = 0; i < jumlahspasi; i++){
        if(!arit.isOperator(a[i])){
            sPost[counter] = a[i];
            counter++;
        }
        else{
            if(a[i] == ")"){
                string opr;
                while(sOpr.top() != "("){
                    sOpr.pop(opr);
                    sPost[counter] = opr;
                    counter++;
                }
                sOpr.pop(opr);
            }
            else{
                if(sOpr.empty() || a[i] == "(")
                    sOpr.push(a[i]);
                else{
                    string opr = sOpr.top();
                    int temp = arit.cekPrecedence(a[i],opr);
                    if(temp == 1 || temp == 2){ // 1. precedence a[i] lebih kecil dari opr. 2. precedence a[i] sama dengan opr.
                        string oprTemp;
                        sOpr.pop(oprTemp);
                        sPost[counter] = oprTemp;
                        counter++;
                        sOpr.push(a[i]);
                    }
                    else if(temp == 3){ // 3. precedence a[i] lebih besar dari opr.
                        sOpr.push(a[i]);
                    }
                }
            }
        }
	}
	while(!sOpr.empty()){
        string oprTemp;
        sOpr.pop(oprTemp);
        sPost[counter] = oprTemp;
        counter++;
	}

	return sPost;
}

/**
* @brief Fungsi untuk membaca ekspresi dalam ekspresi postfix
* @return s - array of string yang telah diparse
**/
string* Ekspresi::fromPostfix(int* ekssize){
    stringstream ss(s);

	int jumlah = 1;
	int sz = s.size();
	for(int i = 0; i < sz; i++){
		if(s[i] == ' ')
			jumlah++;
	}
    *ekssize = jumlah;
	string *a = new string[jumlah];
	for(int i = 0; i < jumlah; i++){
        ss >> a[i];
	}

	return a;
}

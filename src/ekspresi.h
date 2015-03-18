/**
* @file ekspresi.h
**/

#ifndef EKSPRESI_H
#define EKSPRESI_H
#include <string>
#include "stack.h"
#include "operator.h"
#include "Bilangan.h"
#include "kalkulator.h"

using namespace std;
/**
* @class Ekspresi
* @author M. Azwar Adli (13514601)
* @version 1.0
*
* @brief Kelas Ekspresi bertugas untuk mengenali dan mengolah ekspresi masukkan
**/
class Ekspresi{
public:
    /**
    * @brief Konstruktor kelas Ekspresi.
    **/
	Ekspresi();
	/**
    * @brief Konstruktor kelas Ekspresi dengan parameter.
    * @param s - string berupa masukkan file yang akan diolah.
    **/
	Ekspresi(string s);
	/**
    * @brief Destruktor kelas saver.
    **/
	~Ekspresi();

    /**
    * @brief Getter untuk mendapatkan string input.
    * @return s - string input.
    **/
	string getString();

	/**
	* @brief Setter untuk mengubah input.
	* @param s - string input
	**/
	void setString(string s);

	/**
	* @brief Fungsi untuk membaca ekspresi dalam ekspresi prefix
	* @return s - array of string yang telah diparse
	**/
	string* fromPrefix(int*);

	/**
	* @brief Fungsi untuk membaca ekspresi dalam ekspresi infix
	* @return s - array of string yang telah diparse
	**/
	string* fromInfix(int*);
	/**
	* @brief Fungsi untuk membaca ekspresi dalam ekspresi postfix
	* @return s - array of string yang telah diparse
	**/
	string* fromPostfix(int*);

private:
	string s;   //s adalah string input
};

#endif

//
//  Bilangan.h
//  CalculatorOOP
//
//  Created by Fauzan Muhammad Rifqy on 2/23/15.
//  Copyright (c) 2015 Fauzan. All rights reserved.
//

#ifndef __CalculatorOOP__Bilangan__
#define __CalculatorOOP__Bilangan__

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <sstream>

using namespace std;

class bilangan
{
public :
    bilangan();
    bilangan(float);
    ~bilangan();

    //getter
    float get_angka();            //mengembalikan nilai angka
    string get_representasi();  //mengembalikan nilai representasi
    virtual void set(const float&)= 0;
    virtual void set(const string&)= 0;

    //Method
    virtual string retConvertToString(float)= 0;
    virtual float retConvertToFloat(string)= 0;

protected :

    //setter
    void set_angka(float);            //set nilai angka
    void set_representasi(string);  //set nilai representasi
    void add_representasi(string);  //menambahkan nilai representasi di depan
    void put_representasi(string);  //menambahkan nilai representasi di belakang

    //method
    virtual void convert()= 0;     //abstract untuk melakukan convert dari int ke representasi

private :
    string representasi;
    float angka;
};

#endif /* defined(__CalculatorOOP__Bilangan__) */

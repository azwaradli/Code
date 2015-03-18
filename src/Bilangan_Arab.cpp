//
//  Bilangan_Arab.cpp
//  CalculatorOOP
//
//  Created by Fauzan Muhammad Rifqy on 3/1/15.
//  Copyright (c) 2015 Fauzan. All rights reserved.
//

#include "Bilangan_Arab.h"
using namespace std;

Bilangan_Arab::Bilangan_Arab()
{
    set_angka(0);
    set_representasi("");
}
Bilangan_Arab::Bilangan_Arab(float i)
{
    set_angka(i);
    convert();
}

Bilangan_Arab::Bilangan_Arab(string s)
{
    set_angka(retConvertToFloat(s));
    set_representasi(s);
}

Bilangan_Arab::~Bilangan_Arab() {}

void Bilangan_Arab::set(const float &i)
{
    set_angka(i);
    convert();
}

void Bilangan_Arab::set(const string &s)
{
    set_angka(retConvertToFloat(s));
    set_representasi(s);
}

void Bilangan_Arab::convert()
{
    set_representasi(to_string(get_angka()));
}

float Bilangan_Arab::retConvertToFloat(string s)
{
    float i= stof(s.c_str());
    return i;
}

string Bilangan_Arab::retConvertToString(float i)
{
    return to_string(get_angka());
}
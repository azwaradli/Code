//
//  Bilangan_Logika.cpp
//  CalculatorOOP
//
//  Created by Fauzan Muhammad Rifqy on 3/18/15.
//  Copyright (c) 2015 Fauzan. All rights reserved.
//

#include "Bilangan_Logika.h"

Bilangan_Logika::Bilangan_Logika()
{
    set_angka(0);
    set_representasi("");
}

Bilangan_Logika::Bilangan_Logika(float i)
{
    set_angka(i);
    convert();
}

Bilangan_Logika::Bilangan_Logika(string s)
{
    set_angka(retConvertToFloat(s));
}

Bilangan_Logika::~Bilangan_Logika() {}

void Bilangan_Logika::set(float i)
{
    set_angka(i);
    convert();
}

void Bilangan_Logika::set(string s)
{
    set_angka(retConvertToFloat(s));
}

void Bilangan_Logika::convert()
{
    switch ((int)get_angka()) {
        case 0:
            set_representasi("true");
            break;
        case 1:
            set_representasi("false");
            break;
        default:
            break;
    }
}

float Bilangan_Logika::retConvertToFloat(string s)
{
    if (s=="true"||s=="benar"||s=="1") {
        return 1;
    }else if(s=="false"||s=="salah"||s=="0"){
        return 0;
    }
    return -1;
}

string Bilangan_Logika::retConvertToString(float f)
{
    switch ((int)f) {
        case 0:
            return "true";
        case 1:
            return "false";
        default:
            return "error";
    }
}








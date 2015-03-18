//
//  Operator_Logika.cpp
//  CalculatorOOP
//
//  Created by Fauzan Muhammad Rifqy on 3/18/15.
//  Copyright (c) 2015 Fauzan. All rights reserved.
//

#include "Operator_Logika.h"

Operator_Logika::Operator_Logika()
{
    representasi="";
}

Operator_Logika::Operator_Logika(string s)
{
    if (IsOpLogika(s)) {
        representasi= s;
    }else{
        representasi="";
    }
}

Operator_Logika::~Operator_Logika() {}

string Operator_Logika::get_representasi()
{
    return representasi;
}

void Operator_Logika::set_representasi(string s)
{
    if (IsOpLogika(s)) {
        representasi= s;
    }
}

bool Operator_Logika::ret_set_representasi(string s)
{
    if (IsOpLogika(s)) {
        representasi= s;
        return true;
    }else{
        return false;
    }
}

bool Operator_Logika::IsOpLogika(string s)
{
    if (s=="and"||s=="or"||s=="is"||s=="not"||s=="&&"||s=="||"||s=="!"||s=="==")
    {
        return true;
    }
    else
    {
        return false;
    }
}
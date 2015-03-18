//
//  Bilangan.cpp
//  CalculatorOOP
//
//  Created by Fauzan Muhammad Rifqy on 2/23/15.
//  Copyright (c) 2015 Fauzan. All rights reserved.
//

#include "Bilangan.h"

bilangan::bilangan()
{
    angka= 0;
    representasi= "";
}

bilangan::bilangan(float input)
{
    angka= input;
}

bilangan::~bilangan() {}

float bilangan::get_angka()
{
    return angka;
}

string bilangan::get_representasi()
{
    return representasi;
}

void bilangan::set_angka(float input)
{
    angka= input;
}

void bilangan::set_representasi(string input)
{
    representasi= input;
}

void bilangan::add_representasi(string input)
{
    representasi= input+representasi;
}

void bilangan::put_representasi(string input)
{
    representasi= representasi+input;
}
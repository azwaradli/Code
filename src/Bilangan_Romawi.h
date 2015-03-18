//
//  Bilangan_Romawi.h
//  CalculatorOOP
//
//  Created by Fauzan Muhammad Rifqy on 3/11/15.
//  Copyright (c) 2015 Fauzan. All rights reserved.
//

#ifndef __CalculatorOOP__Bilangan_Romawi__
#define __CalculatorOOP__Bilangan_Romawi__

#include "Bilangan.h"

class Bilangan_Romawi : public bilangan
{
public :
    Bilangan_Romawi();
    Bilangan_Romawi(float);
    Bilangan_Romawi(string);
    ~Bilangan_Romawi();
    //Setter
    void set(const float&);
    void set(const string&);
protected :
    void convert();
    float retConvertToFloat(string);
    string retConvertToString(float);
private :
    string insideConvert(int&, const int&, const int&, const string&, const string&, const string&);
};

#endif /* defined(__CalculatorOOP__Bilangan_Romawi__) */

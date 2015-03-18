//
//  Bilangan_Arab.h
//  CalculatorOOP
//
//  Created by Fauzan Muhammad Rifqy on 3/1/15.
//  Copyright (c) 2015 Fauzan. All rights reserved.
//

#ifndef __CalculatorOOP__Bilangan_Arab__
#define __CalculatorOOP__Bilangan_Arab__

#include "Bilangan.h"

class Bilangan_Arab : public bilangan
{
public :
    Bilangan_Arab();
    Bilangan_Arab(float);
    Bilangan_Arab(string);
    ~Bilangan_Arab();
    //Setter
    void set(const float&);
    void set(const string&);
    //Method
    string retConvertToString(float);
protected :
    void convert();
    float retConvertToFloat(string);
};

#endif /* defined(__CalculatorOOP__Bilangan_Arab__) */

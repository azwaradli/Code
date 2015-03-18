//
//  Bilangan_Logika.h
//  CalculatorOOP
//
//  Created by Fauzan Muhammad Rifqy on 3/18/15.
//  Copyright (c) 2015 Fauzan. All rights reserved.
//

#ifndef __CalculatorOOP__Bilangan_Logika__
#define __CalculatorOOP__Bilangan_Logika__

#include <stdio.h>
#include "Bilangan.h"

class Bilangan_Logika : public bilangan
{
public :
    Bilangan_Logika();
    Bilangan_Logika(float);
    Bilangan_Logika(string);
    ~Bilangan_Logika();
    
    void set(float);
    void set(string);
protected :
    void convert();
    float retConvertToFloat(string);
    string retConvertToString(float);
};

#endif /* defined(__CalculatorOOP__Bilangan_Logika__) */

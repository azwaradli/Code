//
//  Operator_Logika.h
//  CalculatorOOP
//
//  Created by Fauzan Muhammad Rifqy on 3/18/15.
//  Copyright (c) 2015 Fauzan. All rights reserved.
//

#ifndef __CalculatorOOP__Operator_Logika__
#define __CalculatorOOP__Operator_Logika__

#include <stdio.h>
#include <string>
using namespace std;

class Operator_Logika
{
public  :
    Operator_Logika();
    Operator_Logika(string);
    ~Operator_Logika();
    
    string get_representasi();
    void set_representasi(string);
    bool ret_set_representasi(string);
    
    bool IsOpLogika(string);
    
private :
    string representasi;
};

#endif /* defined(__CalculatorOOP__Operator_Logika__) */

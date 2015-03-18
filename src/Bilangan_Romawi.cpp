//
//  Bilangan_Romawi.cpp
//  CalculatorOOP
//
//  Created by Fauzan Muhammad Rifqy on 3/11/15.
//  Copyright (c) 2015 Fauzan. All rights reserved.
//

#include "Bilangan_Romawi.h"
using namespace std;

Bilangan_Romawi::Bilangan_Romawi()
{
    set_angka(0);
    set_representasi("");
}
Bilangan_Romawi::Bilangan_Romawi(float i)
{
    set_angka(i);
    convert();
}

Bilangan_Romawi::Bilangan_Romawi(string s)
{
    float i= retConvertToFloat(s);
    set_angka(i);
    set_representasi(s);
}

Bilangan_Romawi::~Bilangan_Romawi() {}

void Bilangan_Romawi::set(const string& s)
{
    float i= retConvertToFloat(s);
    set_angka(i);
    set_representasi(s);
}

void Bilangan_Romawi::set(const float &i )
{
    set_angka(i);
    convert();
}

void Bilangan_Romawi::convert()
{
    int i= (int) get_angka();
    while (i-1000>=0)
    {
        i-= 1000;
        add_representasi("M");
    }
    put_representasi(insideConvert(i, 500, 100, "D", "C","M"));
    put_representasi(insideConvert(i, 50, 10, "L", "X","C"));
    put_representasi(insideConvert(i, 5, 1, "V", "I","X"));
}

float Bilangan_Romawi::retConvertToFloat(string i)
{
    int a= (int) i.length();
    char *temp= new char[a];
    temp= strcpy(temp, i.c_str());
    int j=a-1;
    int hasil= 0;
    
    int f= 0;
    int s= 6;
    
    while (j>=0) {
        switch (temp[j]) {
            case 'M':
                s= 6;
                if (s>=f) {
                    hasil+=1000;
                }else{
                    hasil-=1000;
                }
                j--;
                f= 6;
                break;
            case 'D':
                s= 5;
                if (s>=f) {
                    hasil+=500;
                }else{
                    hasil-=500;
                }
                j--;
                f= 5;
                break;
            case 'C':
                s= 4;
                if (s>=f) {
                    hasil+=100;
                }else{
                    hasil-=100;
                }
                j--;
                f= 4;
                break;
            case 'L':
                s= 3;
                if (s>=f) {
                    hasil+=50;
                }else{
                    hasil-=50;
                }
                j--;
                f= 3;
                break;
            case 'X':
                s= 2;
                if (s>=f) {
                    hasil+=10;
                }else{
                    hasil-=10;
                }
                j--;
                f= 2;
                break;
            case 'V':
                s= 1;
                if (s>=f) {
                    hasil+=5;
                }else{
                    hasil-=5;
                }
                j--;
                f= 1;
                break;
            case 'I':
                s= 0;
                if (s>=f) {
                    hasil+=1;
                }else{
                    hasil-=1;
                }
                j--;
                f= 0;
                break;
            default:
                break;
        }
    }
    delete [] temp;
    return (float) hasil;
}

string Bilangan_Romawi::insideConvert(int& i, const int& sat5, const int& sat1, const string& kar5, const string& kar1, const string& kar10)
{
    string temp= "";
    if (i-sat5>=0)
    {
        i-= sat5;
        temp= kar5;
        int j= 0;
        while (i-sat1>=0) {
            i-= sat1;
            temp += kar1;
            j++;
        }
        if (j==4)
            temp= kar1+kar10;
    }
    else if (i-sat1>=0)
    {
        temp= "";
        int j= 0;
        while (i-sat1>=0) {
            i-= sat1;
            temp += kar1;
            j++;
        }
        if (j==4)
            temp= kar1+kar5;
    }
    return temp;
}

string Bilangan_Romawi::retConvertToString(float f)
{
    string temp= "";
    int i= (int) f;
    while (i-1000>=0)
    {
        i-= 1000;
        temp+="M";
    }
    temp += insideConvert(i, 500, 100, "D", "C","M");
    temp += insideConvert(i, 50, 10, "L", "X","C");
    temp += insideConvert(i, 5, 1, "V", "I","X");
    return temp;
}
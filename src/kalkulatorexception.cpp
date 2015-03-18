#include "kalkulatorexception.h"

int KalkulatorException::num_ex = 0;
char* KalkulatorException::message[] = {"Pembagi tidak boleh 0"};

//ctor
KalkulatorException::KalkulatorException(int id) : msg_id(id){
    num_ex++;
}

KalkulatorException::KalkulatorException(const KalkulatorException& K) : msg_id(K.msg_id){
}

//dtor
KalkulatorException::~KalkulatorException(){
}

//method
char* KalkulatorException::getMessage(){
    return message[msg_id];
}

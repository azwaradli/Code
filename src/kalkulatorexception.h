#ifndef KALKULATOREXCEPTION_H_INCLUDED
#define KALKULATOREXCEPTION_H_INCLUDED

class KalkulatorException{
public:
    //ctor
    KalkulatorException(int);
    KalkulatorException(const KalkulatorException&);
    //dtor
    ~KalkulatorException();
    //method
    char *getMessage();

    const static int DIV_BY_ZERO = 0;

private:
    static int num_ex;
    static char* message[];
    const int msg_id;
};

#endif // KALKULATOREXCEPTION_H_INCLUDED

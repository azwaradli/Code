#include "kalkulator.h"

using namespace std;

Kalkulator::Kalkulator(){
	for(int i=0;i<3;i++)
		mode[i]=0;
	counter=-1;
	top=-1;
}

Kalkulator::~Kalkulator(){

}

bool Kalkulator::isBilArab(){
    return(mode[0]==0);
}
bool Kalkulator::isBilRomawi(){
    return(mode[0]==1);
}
bool Kalkulator::isExpPrefix(){
    return(mode[1]==0);
}
bool Kalkulator::isExpInfix(){
    return(mode[1]==1);
}
bool Kalkulator::isExpPostfix(){
    return(mode[1]==2);
}
bool Kalkulator::isArit(){
    return(mode[2]==0);
}
bool Kalkulator::isLogic(){
    return(mode[2]==1);
}

void Kalkulator::setBilArab(){
	mode[0]=0;
}
void Kalkulator::setBilRomawi(){
	mode[0]=1;
}
void Kalkulator::setExpPrefix(){
	mode[1]=0;
}
void Kalkulator::setExpInfix(){
	mode[1]=1;
}
void Kalkulator::setExpPostfix(){
	mode[1]=2;
}
void Kalkulator::setArit(){
	mode[2]=0;
}
void Kalkulator::setLogic(){
	mode[2]=1;
}

void Kalkulator::setString(string in){
	++top;
	counter=top;
	log[top]=in;
}

void Kalkulator::setHasil(string in){
	hasil[top]=in;
}

void Kalkulator::save(){
	 ofstream myfile ("log.txt", ios::app);
	  if (myfile.is_open()){
	  	myfile <<currentDateTime()<<endl;
	  	for(int i=0;i<top;i++){
			myfile << log[i]<<" = "<<hasil[i];
	  	}
	  	cout<<endl;
    	myfile.close();
  	}
}
void Kalkulator::undo(int n=1){
	cout << log[counter-n]<<" = "<<hasil[counter-n] << endl << endl;
	counter-=n;
}
void Kalkulator::redo(int n=1){
	cout << log[counter+n]<<" = "<<hasil[counter+n] << endl << endl;
	counter+=n;
}
void Kalkulator::show(int n){
	for(int i=top-n;i<=top;i++){
		cout << log[i]<<" = "<<hasil[i] << endl;
	}
	cout << endl;
}
void Kalkulator::showall(){
	for(int i=0;i<=top;i++){
		cout << log[i]<<" = "<<hasil[i] << endl;
	}
	cout << endl;
}

string Kalkulator::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
}

string Kalkulator::split(string &str, char chr){
    string word;
    stringstream stream(str);
    if(getline(stream, word, chr)){
        string::size_type i = str.find(word);
        str.erase(i, word.length()+1); return word;
    }
    else
        return NULL;
}

void Kalkulator::getInfoMode() const{
    string modeBilangan;
    string modeEkspresi;

    if(mode[0] == 0)
        modeBilangan = "Arab";
    else if(mode[0] == 1)
        modeBilangan = "Romawi";

    if(mode[1] == 0)
        modeEkspresi = "Prefix";
    else if(mode[1] == 1)
        modeEkspresi = "Infix";
    else if(mode[1] == 2)
        modeEkspresi = "Postfix";

    cout << "Mode Bilangan: " << modeBilangan << endl;
    cout << "Mode Ekspresi: " << modeEkspresi << endl << endl;
    cout << "Ketik 'setting' untuk mengubah setting kalkulator" << endl;
}

float Kalkulator::calculate(char opr, float opn1, float opn2){
	if(opr == '+')
		return opn1 + opn2;
	else if(opr == '-')
		return opn1 - opn2;
	else if(opr == '/'){
        if(abs(opn2) < 0.0001f )
            throw(KalkulatorException(KalkulatorException::DIV_BY_ZERO));
		return opn1 / opn2;
	}
	else if(opr == '*')
		return opn1 * opn2;
}

float Kalkulator::solveLogic(string opr, float opn1, float opn2){
	if(opr == "and" || opr == "&&")
		return opn1 && opn2;
	else if(opr == "or" || opr == "||")
		return opn1 || opn2;
	else if(opr == "xor"){
        return (opn1 && !opn2) || (!opn1 && opn2);
	}
}

void Kalkulator::calculateAll(){
    Ekspresi e(input);
    string *eks;
    int jumlah;

    if(mode[1] == 0)
        eks = e.fromPrefix(&jumlah);
    else if(mode[1] == 1)
        eks = e.fromInfix(&jumlah);
    else if(mode[1] == 2)
        eks = e.fromPostfix(&jumlah);

    Stack<float> temp;
	Aritmatika arit;
	float opn1,opn2,opn,hasil;
	bilangan *b;
	if(mode[0] == 0){
        b = new Bilangan_Arab();
	}
	else if(mode[0] == 1){
        b = new Bilangan_Romawi();
	}

	for(int i = 0; i < jumlah; i++){
		if(!arit.isOperator(eks[i])){
            b->set(eks[i]);
            opn = b->get_angka();
			//opn = atof(eks[i].c_str());
			temp.push(opn);
		}
		else{
			temp.pop(opn2);
			temp.pop(opn1);
			char opr = arit.getOpr(eks[i]);
			opn = calculate(opr,opn1,opn2);
			temp.push(opn);
		}
	}
	temp.pop(hasil);
	string stemp = b->retConvertToString(hasil);
	cout << "Hasil: " << stemp << " " << endl;
	setHasil(stemp);

}

void Kalkulator::solveLogicAll(){
    bilangan *L;
    L = new Bilangan_Logika();
    int i=-1;
    string opn1,opn2,pch,opr;
    Stack<string> temp;
    do{
        pch=split(input,' ');
        i++;
        if(pch=="and" || pch=="&&" || pch=="or" || pch=="||" || pch=="xor"){
            opr=pch;
            temp.pop(opn1);
            pch=split(input,' ');
            opn2=pch;
            float x=solveLogic(opr,L.retConvertToFloat(opn1),L.retConvertToFloat(opn2));
            cout<<endl<<L.retConvertToString(x)<<endl;
        }
        else{
            temp.push(pch);
        }
    }while(in.length());
}

void Kalkulator::run(){
    do{
        string s;
        getInfoMode();
        cout << "> ";
        getline(cin,s);
        input = s;

        if(input == "exit");
        else if(input == "setting"){
            help();
            string temp;
            cout << "> ";
            getline(cin,temp);
            setMode(temp);
        }
        else{
            setString(input);
            if(isArit()){
                calculateAll();
            }
            else if (isLogic()){
                solveLogicAll();
            }
        }
        /*else
            throw exception*/
    }
    while(input != "exit");
}

void Kalkulator::help(){
    cout << "1. set <mode> <pilihan mode>" << endl;
    cout << "2. undo <n>" << endl;
    cout << "3. redo <n>" << endl;
    cout << "4. show <n>" << endl;
    cout << "5. showall" << endl;
    cout << "6. cancel" << endl;
}

void Kalkulator::setMode(string in){
  	string pch=split(in,' ');
    if(pch=="set") {
        pch=split(in,' ');
        if(pch=="bilangan"){
            pch=split(in,' ');
            if(pch=="arab") {
                setBilArab();
            }
            else if(pch=="romawi") {
                setBilRomawi();
            }
        }
        else if(pch=="ekspresi"){
            pch=split(in,' ');
            if(pch=="prefix") {
                setExpPrefix();
            }
            else if(pch=="infix") {
                setExpInfix();
            }
            else if(pch=="postfix") {
                setExpPostfix();
            }
        }
        else if(pch=="aritmatika"){
            setArit();
        }
        else if(pch=="logika") {
            setLogic();
        }
    }
    else if(pch=="undo"){
        string num=split(in,' ');
        int n=atoi(num.c_str());
        if(n){
            undo(n);
        }
    }
    else if(pch=="redo"){
        string num=split(in,' ');
        int n=atoi(num.c_str());
        if(n){
            redo(n);
        }
    }
    else if(pch=="show"){
        string num=split(in,' ');
        int n=atoi(num.c_str());
        if(n){
            show(n);
        }
    }
    else if(pch=="showall"){
        showall();
    }
}

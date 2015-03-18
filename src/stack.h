#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

template <class T>
class Stack{
public:
	Stack();
	Stack(int);
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	~Stack();

	void push(T);
	void pop(T&);
	bool empty() const;
	T top();
	int size();

private:
    bool isFull() const;
	int topStack;
	T *data;
	int sz;
	const int defaultSize;
};

template <class T>
Stack<T>::Stack(): defaultSize(100){
    sz = defaultSize;
	topStack = -1;
	data = new T[sz];
}

template <class T>
Stack<T>::Stack(int n): defaultSize(100){
    sz = n;
    topStack = -1;
    data = new T[sz];
}

template <class T>
Stack<T>::~Stack(){
	topStack = -1;
	delete [] data;
}

template <class T>
void Stack<T>::push(T input){
	if(!isFull()){
        topStack++;
        data[topStack] = input;
	}
	else{
        T *datatemp = new T[sz*2];
        assert(datatemp != NULL);
        for(int i = 0; i < sz; i++){
            datatemp[i] = data[i];
        }
        delete [] data;
        data = datatemp;
        sz = sz+10;
        topStack++;
        data[topStack] = input;
	}
}

template <class T>
void Stack<T>::pop(T& output){
	assert(!empty());
    output = top();
    topStack--;
}

template <class T>
bool Stack<T>::empty() const{
    if(topStack == -1)
        return true;
    else
        return false;
}

template <class T>
bool Stack<T>::isFull() const{
    return (topStack == sz-1);
}

template <class T>
T Stack<T>::top(){
    return data[topStack];
}

template <class T>
int Stack<T>::size(){
    return sz;
}

#endif

#include "stack.h"

using namespace std;

vector<float> vStack;

Stack::Stack(): defaultSize(10){
	setTop(0);
	vStack.resize(defaultSize);
}

Stack::~Stack(){
	setTop(0);
	vStack.clear();
}

void Stack::Push(float input){
	setTop(getTop() + 1);
	setElmt(input);
}

void Stack::Pop(float& output){
	output = vStack[topStack];
	setTop(getTop() - 1);
}

void Stack::setTop(float input){
	topStack = input;
}

void Stack::setElmt(float input){
	vStack[getTop()] = input;
}

float Stack::getTop(){
	return topStack;
}

int Stack::getDefault(){
	return defaultSize;
}

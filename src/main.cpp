#include "stack.h"
#include <iostream>

using namespace std;

int main(){
	float i;
	Stack myStack;
	myStack.Push(10);
	myStack.Pop(i);
	cout << i << endl;

	return 0;
}

#ifndef STACK_H
#define STACK_H
#include <vector>

class Stack{
public:
	Stack();
	~Stack();
	void Push(float);
	void Pop(float&);
	void setTop(float);
	void setElmt(float);
	float getTop();
	int getDefault();

private:
	float topStack;
	float *data;
	const int defaultSize;
};

#endif

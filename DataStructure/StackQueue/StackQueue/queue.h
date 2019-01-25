#ifndef STACK_QUEUE_H_
#define STACK_QUEUE_H_
#include<stack>

//implement queue use stack
template<class Type>
class Queue {
private:
	std::stack<Type> cache1, cache2;
public:
	void push(Type val);
	void pop();
	Type front();
	Type back();
	int size();
	bool empty();
};


#endif
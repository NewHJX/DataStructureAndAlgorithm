#include <iostream>
#include "queue.h"

template<class Type>
void Queue<Type>::push(Type val) {
	cache1.push(val);
}

template<class Type>
void Queue<Type>::pop() {
	if (cache1.empty() && cache2.empty()) return;
	//notice 这里如果判断!cache2.empty会有代码冗余  
	if (cache2.empty())
	{
		while (!cache1.empty()) {
			cache2.push(cache1.top());
			cache1.pop();
		}
	}
	cache2.pop();
}

template<class Type>
Type Queue<Type>::front() {
	if (cache1.empty() && cache2.empty()) return NULL;
	if (cache2.empty()) {
		while (!cache1.empty()) {
			cache2.push(cache1.top());
			cache1.pop();
		}
	}
	return cache2.top();
}

template<class Type>
Type Queue<Type>::back() {
	if (cache1.empty() && cache2.empty()) return NULL;
	if (cache1.empty()) {
		while (!cache2.empty()) {
			cache1.push(cache2.top());
			cache2.pop();
		}
	}
	return cache1.top();
}

template<class Type>
int Queue<Type>::size() {
	return cache1.size() + cache2.size();
}

template<class Type>
bool Queue<Type>::empty() {
	return cache1.empty() && cache2.empty();
}
int main() {
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	std::cout << "front:" << queue.front() << " size:" << queue.size() << " is empty:" << queue.empty() << std::endl;
	queue.pop();
	std::cout << "front:" << queue.front() << " size:" << queue.size() << " is empty:" << queue.empty() << std::endl;
	queue.pop();
	std::cout << "size:" << queue.size() << " is empty:" << queue.empty() << std::endl;
	getchar();
	return 0;
}
#pragma once
#include<map>
struct DLinkedNode {
	int value;
	DLinkedNode *pre;
	DLinkedNode *next;
	DLinkedNode():value(0),pre(NULL),next(NULL){}
	DLinkedNode(int val):value(val),pre(NULL),next(NULL){}
};
class CLru {
private:
	std::map<int,DLinkedNode*> page_cache;
	int capacity;
	int count;
	DLinkedNode *head, *tail;
public:
	CLru(int cap);
	int visit_page(int val);
	void show_cache();
};
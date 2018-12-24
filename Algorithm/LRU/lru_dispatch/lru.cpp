#include "lru.h"
CLru::CLru(int cap) {
	count = 0;
	capacity = cap < 0 ? 0 : cap;
	head = new DLinkedNode();
	tail = new DLinkedNode();
	head->next = tail;
	tail->pre = head;
}
int CLru::visit_page(int val) {
	if (capacity == 0) {
		printf("capacity equal with 0!\n");
		return -1;
	}
	std::map<int, DLinkedNode*>::iterator it = page_cache.find(val);
	if (page_cache.end() != it) {
		DLinkedNode *p = it->second->pre;
		DLinkedNode *n = it->second->next;
		it->second->next = head->next;
		head->next->pre = it->second;
		head->next = it->second;
		it->second->pre = head;
		p->next = n;
		n->pre = p;
	}
	else {
		//full cache 
		if (page_cache.size() >= capacity) {
			DLinkedNode *tail_pre = tail->pre;
			DLinkedNode *tail_pp = tail_pre->pre;
			DLinkedNode *cur = new DLinkedNode(val);
			tail_pp->next = tail;
			tail->pre = tail_pp;
			page_cache.erase(tail_pre->value);
			delete tail_pre;
			DLinkedNode *head_next = head->next;
			head->next = cur;
			cur->pre = head;
			cur->next = head_next;
			head_next->pre = cur;
			page_cache.insert({ val,cur });
		}
		else {
			DLinkedNode *head_next = head->next;
			DLinkedNode *cur = new DLinkedNode(val);
			page_cache.insert({ val,cur });
			head->next = cur;
			cur->pre = head;
			cur->next = head_next;
			head_next->pre = cur;
		}
	}
	show_cache();
	return 0;
}
void CLru::show_cache() {
	for (auto it : page_cache) {
		printf("%d ", it.first);
	}
	printf("\n");
}


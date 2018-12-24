#include "lru.h"
int main() {
	CLru lru_page_replace(1);
	lru_page_replace.visit_page(7);
	lru_page_replace.visit_page(0);
	lru_page_replace.visit_page(1);
	lru_page_replace.visit_page(2);
	lru_page_replace.visit_page(0);
	lru_page_replace.visit_page(3);
	lru_page_replace.visit_page(0);
	lru_page_replace.visit_page(4);
	getchar();
	return 0;
}
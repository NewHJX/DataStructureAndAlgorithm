#include<iostream>

using namespace std;

struct LinkList {
	int val;
	struct LinkList* next;
	LinkList(int v) :val(v), next(NULL) {}
};

int main() {
	LinkList* pHead = new LinkList(1);

	LinkList* pCur = pHead;
	for (int i = 2; i < 10; i++) {
		LinkList* node = new LinkList(i);
		pCur->next = node;
		pCur = pCur->next;
	}

	for (LinkList** pp = &pHead; *pp;) {
		//此处可以封装一个删除函数
		if ((*pp)->val == 5) {
			LinkList* pTmp = *pp;
			//修改next的地址
			*pp = (*pp)->next;
			delete pTmp;
			pTmp = NULL;
			break;
		}
		//pp指针保留next的地址
		pp = &(*pp)->next;
	}

	for (LinkList** pp = &pHead; *pp;) {
		printf("%d ", (*pp)->val);
		pp = &(*pp)->next;
		//暂不考虑其他资源的释放
	}
	printf("\n");
	getchar();
	return 0;
}
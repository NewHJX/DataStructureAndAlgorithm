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
		//�˴����Է�װһ��ɾ������
		if ((*pp)->val == 5) {
			LinkList* pTmp = *pp;
			//�޸�next�ĵ�ַ
			*pp = (*pp)->next;
			delete pTmp;
			pTmp = NULL;
			break;
		}
		//ppָ�뱣��next�ĵ�ַ
		pp = &(*pp)->next;
	}

	for (LinkList** pp = &pHead; *pp;) {
		printf("%d ", (*pp)->val);
		pp = &(*pp)->next;
		//�ݲ�����������Դ���ͷ�
	}
	printf("\n");
	getchar();
	return 0;
}
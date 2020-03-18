#include <iostream>
#include <stack>
using namespace std;

typedef struct Tree {
	struct Tree* left;
	struct Tree* right;
	int val;
	Tree(int value) :val(value), left(NULL), right(NULL) {}
}*pTree;

void PreTraverse(pTree pRoot) {
	if (pRoot == NULL) {
		return;
	}

	stack<pTree> stackTree;
	stackTree.push(pRoot);
	
	while (!stackTree.empty()) {
		pTree pTmp = stackTree.top();
		cout << pTmp->val;
		stackTree.pop();

		if (pTmp->right) stackTree.push(pTmp->right);
		if (pTmp->left) stackTree.push(pTmp->left);
	}

	cout << endl;
}

void MidTraverse(pTree pRoot) {
	if (pRoot == NULL) {
		return;
	}

	stack<pTree> stackTree;

	pTree cur = pRoot;
	while (!stackTree.empty() || cur) {

		while (cur) {
			stackTree.push(cur);
			cur = cur->left;
		}

		if (!stackTree.empty()) {
			pTree pTmp = stackTree.top();
			stackTree.pop();

			cout << pTmp->val;

			cur = pTmp->right;
		}
	}

	cout << endl;
}

void PostTraverse(pTree pRoot) {
	if (pRoot == NULL) {
		return;
	}

	stack<pTree> stackTree;
	stackTree.push(pRoot);
	stack<pTree> stackRes;

	while (!stackTree.empty()) {

		pTree pTmp = stackTree.top();
		stackTree.pop();
		stackRes.push(pTmp);
		if (pTmp->left) stackTree.push(pTmp->left);
		if (pTmp->right) stackTree.push(pTmp->right);
	}

	while (!stackRes.empty()) {
		pTree pTmp = stackRes.top();
		stackRes.pop();
		cout << pTmp->val;
	}
	cout << endl;

}

//            1
//		    /  \
//         2    3
//        / \  / \
//       4   5 6  7
void ConstructTree(pTree pRoot) {
	pRoot->val = 1;
	pTree pLeft = new Tree(2);
	pTree pLLeft = new Tree(4);
	pTree pLRight = new Tree(5);
	pLeft->left = pLLeft;
	pLeft->right = pLRight;

	pTree pRight = new Tree(3);
	pTree pRLeft = new Tree(6);
	pTree pRRight = new Tree(7);
	pRight->left = pRLeft;
	pRight->right = pRRight;

	pRoot->left = pLeft;
	pRoot->right = pRight;

	//不考虑内存释放
}

int main() {

	pTree pRoot = new Tree(1);

	ConstructTree(pRoot);

	//1245367
	PreTraverse(pRoot);
	
	//4251637
	MidTraverse(pRoot);

	//先序遍历是先自己后左再右
	//如果先自己后右再左遍历一次，然后逆序这个序列就是后序遍历序列
	//4526731
	PostTraverse(pRoot);

	getchar();
	return 0;
}
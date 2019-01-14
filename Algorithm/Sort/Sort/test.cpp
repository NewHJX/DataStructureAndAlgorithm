#include "insertsort.h"
#include "quicksort.h"
#include "heapsort.h"

void PrintVector(std::vector<int> nums) {
	for (int i = 0; i < nums.size(); ++i) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

void PrintListNode(ListNode* list) {
	while (list != NULL) {
		printf("%d ", list->val_);
		list = list->next;
	}
	printf("\n");
}

int main() {
	//insert sort
	std::vector<int> nums{ 9,8,7,6,5,4 };
	InsertSort(nums.begin(), nums.end());
	PrintVector(nums);
	//quick sort
	nums = { 9,8,7,6,5,4 };
	QuickSort(nums.begin(), nums.end());
	PrintVector(nums);

	nums = { 9,8,7,6,5,4 };
	AnotherQuickSort(nums.begin(), nums.end());
	PrintVector(nums);
	ListNode *node1 = new ListNode(5);
	ListNode *node2 = new ListNode(4);
	node1->next = node2;
	ListNode *node3 = new ListNode(7);
	node2->next = node3;
	ListNode *node4 = new ListNode(6);
	node3->next = node4;
	ListNode *node5 = new ListNode(9);
	node4->next = node5;
	ListNode *node6 = new ListNode(8);
	node5->next = node6;
	QuickSortForLinkedList(node1);
	PrintListNode(node1);
	//heap sort
	nums = { 9,8,2,3,6,5,1 };	HeapSort(nums);
	PrintVector(nums);
	getchar();
	return 0;
}
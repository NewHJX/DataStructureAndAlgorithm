#include "quicksort.h"

const int GetMedian(int a, int b, int c) {
	if (a < b)
		if (b < c) return b;
		else if (a < c) return c;
		else return a;
	else if (a < c) return a;
	else if (b < c) return c;
	else return b;
}

std::vector<int>::iterator QuickSortPartition(std::vector<int>::iterator first, std::vector<int>::iterator last, int pivot) {
	while (true) {
		while (*first < pivot) ++first;
		--last;
		while (*last > pivot) --last;
		if (first >= last) return first;
		std::iter_swap(first, last);
		++first;
	}
}

//挖坑填坑法，很好理解
std::vector<int>::iterator AnotherQuickSortPartition(std::vector<int>::iterator first, std::vector<int>::iterator last, int pivot)
{
	while (first < last) {
		--last;
		while (first < last && *last > pivot) --last;
		*first = *last;
		++first;
		while (first < last && *first < pivot) ++first;
		*last = *first;
	}
	*first = pivot;
	return first;
}

void QuickSort(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	int size = last - first;
	if (size <= 1) return;
	int median = GetMedian(*first, *(first + ((last - 1 - first) / 2)), *(last - 1));
	std::vector<int>::iterator partition = QuickSortPartition(first, last, median);
	if (first < partition) QuickSort(first, partition);
	if (partition + 1 < last) QuickSort(partition + 1, last);
}

void AnotherQuickSort(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	int size = last - first;
	if (size <= 1) return;
	std::vector<int>::iterator partition = QuickSortPartition(first, last, *first);
	if (first < partition) QuickSort(first, partition);
	if (partition + 1 < last) QuickSort(partition + 1, last);
}

//默认pivot为head节点
//cur指针用来标记用来放置比pivot小的节点
//explore指针用来搜索比pivot小的节点
//pre指针用来返回pivot的最终位置
void QuickSortPartitionForLinkedList(ListNode *head, ListNode *tail) {
	if (head == NULL || head->next == NULL || head->next == tail) return;
	ListNode *pre = head;
	ListNode *cur = head->next;
	ListNode *explore = head->next;
	while (explore != NULL) {
		if (explore->val_ < head->val_)
		{
			std::swap(explore->val_, cur->val_);
			pre = pre->next;
			cur = cur->next;
		}
		explore = explore->next;
	}
	std::swap(pre->val_, head->val_);
	QuickSortPartitionForLinkedList(head, pre);
	QuickSortPartitionForLinkedList(pre->next, tail);
}

void QuickSortForLinkedList(ListNode *list) {
	QuickSortPartitionForLinkedList(list, NULL);
}
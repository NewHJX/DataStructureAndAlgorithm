#ifndef SORT_QUICKSORT_H_
#define SORT_QUICKSORT_H_

#include<vector>
#include<algorithm>
struct ListNode{
	int val_;
	ListNode *next;
	ListNode(int val) :val_(val), next(NULL) {}
};

const int GetMedian(int a, int b, int c);
std::vector<int>::iterator QuickSortPartition(std::vector<int>::iterator first, std::vector<int>::iterator last, int pivot);
std::vector<int>::iterator AnotherQuickSortPartition(std::vector<int>::iterator first, std::vector<int>::iterator last, int pivot);
void QuickSort(std::vector<int>::iterator first, std::vector<int>::iterator last);
void AnotherQuickSort(std::vector<int>::iterator first, std::vector<int>::iterator last);
void QuickSortPartitionForLinkedList(ListNode *head,ListNode *tail);
void QuickSortForLinkedList(ListNode *list);
#endif
#include "mergesort.h"

void Merge(std::vector<int>& res, std::vector<int>& left, int leftcount, std::vector<int>& right, int rightcount) {
	int i = 0, j = 0, k = 0;
	while (i < leftcount && j < rightcount) {
		if (left[i] < right[j]) res[k++] = left[i++];
		else res[k++] = right[j++];
	}
	while (i < leftcount) res[k++] = left[i++];
	while (j < rightcount) res[k++] = right[j++];
}

void MergeSort(std::vector<int>& res, int length) {
	if (length < 2) return;
	auto mid = (res.end() - res.begin()) / 2;
	std::vector<int> left(res.begin(), res.begin() + mid);
	std::vector<int> right(res.begin()+mid, res.end());
	MergeSort(left, left.size());
	MergeSort(right, right.size());
	Merge(res, left, left.size(), right, right.size());
}

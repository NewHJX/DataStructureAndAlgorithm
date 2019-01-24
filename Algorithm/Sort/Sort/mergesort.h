#ifndef SORT_MERGESORT_H_
#define SORT_MERGESORT_H_

#include<vector>
#include<algorithm>

void Merge(std::vector<int>& res, std::vector<int>& left, int leftcount, std::vector<int>& right, int rightcount);
void MergeSort(std::vector<int>& res, int length);

#endif
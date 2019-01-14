#ifndef SORT_HEAPSORT_H_
#define SORT_HEAPSORT_H_

#include<vector>
#include<algorithm>

void MakeBigHeap(std::vector<int>& heap, int size);
void HeapSort(std::vector<int>& heap);

#endif
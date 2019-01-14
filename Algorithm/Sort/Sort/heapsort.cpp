#include "heapsort.h"

void HeapSort(std::vector<int>& heap) {
	int size = heap.size();
	if (size <= 1) return;
	for (int i = 0; i < size; ++i) {
		MakeBigHeap(heap, size - i);
		std::swap(heap[0], heap[size - i - 1]);
	}
}
void MakeBigHeap(std::vector<int>& heap, int size) {
	if (size <= 1) return;
	//需要重新编排的父节点index
	int parent = (size - 2) / 2;
	for (int i = parent; i >= 0; --i) {
		if (heap[2 * i + 1] > heap[i])
			if ((2 * i + 2) < size && heap[2 * i + 2] > heap[2 * i + 1]) {
				std::swap(heap[2 * i + 2], heap[i]);
			}
			else {
				std::swap(heap[2 * i + 1], heap[i]);
			}
		else if ((2 * i + 2) < size && heap[2 * i + 2] > heap[i]) {
			std::swap(heap[2 * i + 2], heap[i]);
		}
	}
}
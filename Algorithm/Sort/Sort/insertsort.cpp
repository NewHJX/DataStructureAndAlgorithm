#include "insertsort.h"
//from sgi stdl

void LinearInsert(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	int value = *last;
	if (value < *first) {
		std::copy_backward(first, last, last + 1);
		*first = value;
	}
	else {
		auto next = last;
		--next;
		while (value < *next) {
			*last = *next;
			last = next;
			--next;
		}
		*last = value;
	}
}

void InsertSort(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	if (first == last) return;
	for (auto i = first + 1; i != last; ++i) {
		LinearInsert(first, i);
	}
}

int main() {
	std::vector<int> nums{ 9,8,7,6,5,4 };
	InsertSort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	getchar();
	return 0;
}
#include<vector>
#include<algorithm>
#include<iostream>

//NextPermutation
//step 1:从尾部开始寻找两个相邻的元素，两个元素索引为i和ii（i<ii）
//此时i后面的所有元素都是降序排列的,也就是说i之后的子序列的字典序最大
//step 2:此时需要进位了，选取新的位于i后且比*i大的元素来代替*i
//step 3:并将i之后的元素全部颠倒，因为之前是降序，颠倒后就是字典序最小的以新*i开头的最小字典序
//https://www.quietlove.site/ArticleController?command=articledetail&&artid=151

bool NextPermutation(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	if (first == last) return false;
	std::vector<int>::iterator i = first;
	++i;
	if (i == last) return false;
	i = last;
	--i;
	for (;;) {
		std::vector<int>::iterator ii = i;
		--i;
		if (*i < *ii) {
			std::vector<int>::iterator j = last;
			while (!(*i < *--j));
			std::iter_swap(i, j);
			std::reverse(ii, last);
			return true;
		}
		if (i == first) {
			std::reverse(first, last);
			return false;
		}
	}
}
bool PrevPermutation(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	if (first == last) return false;
	std::vector<int>::iterator i = first;
	++i;
	if (i == last) return false;
	i = last;
	--i;
	for (;;) {
		std::vector<int>::iterator ii = i;
		--i;
		if (*i > *ii) {
			std::vector<int>::iterator j = last;
			while (!(*i > *--j));
			std::iter_swap(i, j);
			std::reverse(ii, last);
			return true;
		}
		if (i == first) {
			std::reverse(first, last);
			return false;
		}
	}
}

void PrintVector(std::vector<int> &nums) {
	for (auto& num : nums) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}
int main() {
	std::vector<int> nums = { 1,2,3 };
	while (NextPermutation(nums.begin(), nums.end())) {
		PrintVector(nums);
	}
	//notice now nums:1,2,3
	getchar();
	return 0;
}
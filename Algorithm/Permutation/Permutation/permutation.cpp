#include<vector>
#include<algorithm>
#include<iostream>

//NextPermutation
//step 1:��β����ʼѰ���������ڵ�Ԫ�أ�����Ԫ������Ϊi��ii��i<ii��
//��ʱi���������Ԫ�ض��ǽ������е�,Ҳ����˵i֮��������е��ֵ������
//step 2:��ʱ��Ҫ��λ�ˣ�ѡȡ�µ�λ��i���ұ�*i���Ԫ��������*i
//step 3:����i֮���Ԫ��ȫ���ߵ�����Ϊ֮ǰ�ǽ��򣬵ߵ�������ֵ�����С������*i��ͷ����С�ֵ���
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
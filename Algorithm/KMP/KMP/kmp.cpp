#include<vector>
#include<string>
#include<iostream>


//s:待匹配字符串
//p:模式串
//next:记录当前位置前面的最大匹配前后缀长度
//https://blog.csdn.net/v_july_v/article/details/7041827

//next must be allocated by caller
void GetNext(std::string p, std::vector<int>& next) {
	int p_len = p.size();
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < p_len - 1) {
		if (k == -1 || p[j] == p[k]) {
			++k;
			++j;
			next[j] = k;
		}
		else {
			k = next[k];
		}
	}
}

int KmpSearch(std::string s, std::string p, std::vector<int> next) {
	int i = 0;
	int j = 0;
	int s_len = s.size();
	int p_len = p.size();
	while (i < s_len && j < p_len) {
		if (j == -1 || s[i] == p[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j == p_len) {
		return i - j;
	}
	else {
		return -1;
	}
}


int main() {
	std::string s = "bbc abcdab abcdabcdabde";
	std::string p = "abcdabd";
	std::vector<int> next(p.size(), -1);
	GetNext(p, next);
	std::cout << KmpSearch(s, p, next) << std::endl;
	getchar();
	return 0;
}
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>


void printVector(std::vector<int> tmp) {
	for (int i = 0; i < tmp.size(); i++) {
		std::cout << tmp[i] << " ";
	}
	std::cout << "\n";
}

void printStack(std::stack<int>& tmp_s) {
	int size_ = tmp_s.size();
	std::vector<int> nums(size_);
	for (int i = 0; i < size_; i++) {
		nums[i] = tmp_s.top();
		tmp_s.pop();
	}

	for (int i = size_ - 1; i >= 0; i--) {
		tmp_s.push(nums.at(i));
	}

	std::reverse(nums.begin(), nums.end());
	printVector(nums);
}

int main() {
	std::stack<int> tmp_s;
	for (int i = 0; i < 10; i++) {
		tmp_s.push(i);
	}
	printStack(tmp_s);
	printStack(tmp_s);
}
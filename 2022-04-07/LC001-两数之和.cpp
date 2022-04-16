//LC001:给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。
//来源:Leetcode
//url:https://leetcode-cn.com/problems/two-sum/
//programmer : Charming

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> ans;
	for (int i = 0; i < nums.size()-1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target) {
				ans.push_back(i);
				ans.push_back(j);
			}
		}
	}
	return ans;
}

//更快(on)
vector<int> twoSum_2(vector<int>& nums, int target) {
	vector<int> ans;
	unordered_map<int, int> dick;
	for (int i = 0; i < nums.size(); i++) {
		dick[nums[i]] = i;
	}
	for (int i = 0; i < nums.size(); i++) {
		int point = target - nums[i];
		auto it = dick.find(point);
		if (it != dick.end() && it->second != i) {
			ans.push_back(i);
			ans.push_back(it->second);
			break;
		}
	}
	return ans;
}

int main(){
	vector<int> nums = { 2,7,11,15 };
	nums = twoSum_2(nums, 9);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i]<<' ';
	}
	cout << endl;
	return 1;
}
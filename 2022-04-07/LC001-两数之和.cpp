//LC001:����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
//����԰�����˳�򷵻ش𰸡�
//��Դ:Leetcode
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

//����(on)
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
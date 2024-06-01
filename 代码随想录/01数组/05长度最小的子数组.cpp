//给定一个含有n个正整数的数组和一个正整数s，找出该数组中满足其和≥s的长度最小的连续子数组，并返回其长度。如果不存在符合条件的子数组，返回0。

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	int minSubArrayLen(int target, vector<int>&nums) {
		int minLength = INT32_MAX;
		int sum = 0;
		int i = 0;//滑动窗口起始位置
		int subLength = 0;//滑动窗口的长度
		for (int j = 0; j < nums.size(); j++)
		{
			sum += nums[j];
			//此时已满足条件
			while (sum >= target) {
				subLength = j - i + 1;//取子串的长度
				minLength = minLength < subLength ? minLength : subLength;
				
				//sum -= nums[i++];// 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
				sum -= nums[i];//下一步的和
				i++;//起始位置往下移
			}
		}
		// 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
		return minLength == INT32_MAX ? 0 : minLength;
	}
};
int main() {
	vector<int> a = { 2,3,1,2,4,3 };
	int target = 7;
	Solution s;
	int b = s.minSubArrayLen(target,a);
	printf("%d", b);
	return 0;
}
/*
【题目】：给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度
【解题思路】：查找目标值+
【代码逻辑】；
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			if (nums[i] == val)// 发现需要移除的元素，就将数组集体向前移动一位
			{
				for (int j = i+1; j < size; j++)
				{
					nums[j - 1] = nums[j];//元素前移
					//nums[j] = nums[j + 1];//j可能会越界

				}
				i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
				size--; // 此时数组的大小-1
			}
		}
		return size;
	}
};
int main() {
	vector<int> a= { 2, 3, 5,3, 7, 8 };
	int m = 3;
	int size = 0;
	Solution s;
	size=s.removeElement(a, m);
	cout << size << endl;
	for (int i = 0; i < size; i++)
	{
		cout << a[i];
	}
	cout << endl<<" ";
	return 0;
}
/*
【题目】：
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1
【解题思路】：由于数组是有序的，所以每次只取处于数组最中间的那个值，与目标值进行对比，然后更新搜索区间，直到找到为止
【代码逻辑】：
①确定初始搜索区间：
起始位置：left=0;
结束位置：right=size-1;
中间值：middle=left+(right-left)/2;
②查找+更新搜索区间
if nums[middle]>target=target:找到返回
if nums[middle]<target：说明target在middle右边,则left=middle+11
if nums[middle]>target:说明target在middle左边,则right=middle-1
【注意】：
一般middle = (left + right) / 2，但是left + right可能会造成数据溢出，
故换种表达方式：middle=left+(right-left)/2;
参考链接：https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E6%80%9D%E8%B7%AF
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	int search( vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{

			//int middle = (left + right) / 2;
			int middle = left + ((right - left) / 2);// 防止(left + right) 溢出 等同于(left + right)/2
			if (nums[middle] > target)
			{
				right = middle - 1;
			}
			else if (nums[middle] < target)
			{
				left = middle + 1;
			}
			else
			{
				return middle;
			}
		}
		return -1;//未找到
	}
};
int main()
{
	vector<int> a;
	a = {1,3,6,8};
	int target = 6;
	Solution s;
	cout << s.search(a, target) << endl;
}
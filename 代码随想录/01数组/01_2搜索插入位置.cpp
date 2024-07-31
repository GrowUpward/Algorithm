/*
* 
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。

示例 1:
输入: [1,3,5,6], 5
输出: 2

示例 2:
输入: [1,3,5,6], 2
输出: 1
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //暴力法
    int searchInsert1(vector<int>& nums, int target) {
        int i = 0;
        for (i=0; i<nums.size(); i++)
        {

            //if (nums[i] < target)//只要小就+
            //{
            //    cout << i<<" ooo" << endl;//不做处理
            //}
            //else
            //{
            //    return i;//=和>返回的结果一样，都是此位置
            //}
            if (nums[i] >= target)
            {
                return i;
            }
        }
        return i;
    }
    //二分法
	//【解题思路】：先搜索一遍，找到就返回索引（二分法） + 没找到怎么返回
	int searchInsert2(vector<int>&nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;

		while (left <= right)
		{
			int middle = left + (right - left) / 2;
			if (nums[middle] > target)//target在左边
			{
				right = middle - 1;//更新左区域的右边界
			}
			else if (nums[middle] < target)//target在右边
			{
				left = middle + 1;//更新右区域的左边界
			}
			else // 找到了target
			{
				return middle;//返回索引
			}
		}
		//以“左闭右闭”`while(left <= right)`的方式，要是没找到，结束循环后，left > right，且left = right + 1。

		//没找到的可能情况有以下3种：
		//	①目标值在数组所有元素之前，此时left = 0, right = -1, 待插入位置应为0
		//	②目标值在插入数组所有元素之中，此时待插入元素应位于right和left中间，待插入位置应为right + 1或left
		//	③目标值在数组所有元素之后的情况，此时left = size, right = size - 1
		//	所有，应return right + 1 或者return left
		return right + 1;
	}

};
int main()
{
    vector<int>nums;
    nums = { 1,3,6,8 };
    int target =5;
    Solution s;
    //cout << s.searchInsert1(nums, target);
    cout << s.searchInsert2(nums, target);

}

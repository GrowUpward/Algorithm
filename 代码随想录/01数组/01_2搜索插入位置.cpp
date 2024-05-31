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
    int searchInsert2(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right-left) / 2;
            if (target == nums[mid])
            {
                return mid;//找到了相等的
            }
            else if (target < nums[mid])
            {
                right = mid - 1;//到左边找
            }
            else//target >left
            {
                left = mid + 1;
            }
        }
        return left;//right+1 没找到，结束
    }

};
int main()
{
    vector<int>nums;
    nums = { 1,3,6,8 };
    int target =6;
    Solution s;
    cout << s.searchInsert1(nums, target);
    cout << s.searchInsert2(nums, target);

}
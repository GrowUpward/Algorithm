/*
* 
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //暴力法
    int* searchInsert1(vector<int>& nums, int target)
    {
        int i = 0;
        int a[2];
        for (; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                a[0] = i;
                //2:=，3：=,进入，再加了一次
                while (nums[i] == target && i < nums.size())
                {
                    i++;//直到找到最后一个相等的
                }
                a[1] = i-1;//最后一次等的时候进入了循环，加了，这里要减去
                return a;
            }
        }
        a[0] = a[1] = -1;
        return a;
    }
    //二分法
    int* searchInsert2(vector<int>& nums, int target) {
        int a[2];
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right-left) / 2;
            if (target == nums[mid])
            {
                return a;//找到了相等的
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
        return a;//right+1 没找到，结束
    }

};
int main()
{
    vector<int>nums;
    nums = { 1,3,6,8 };
    int target =5;//[2,3]
    Solution s;
    //int a[2];
    int* p;
    p=s.searchInsert1(nums, target);
    cout << "[" << p[0] << "," << p[1] << "]" << endl;
    cout <<endl;
    p = s.searchInsert2(nums, target);
    cout << "[" << p[0] << "," << p[1] << "]" << endl;

}
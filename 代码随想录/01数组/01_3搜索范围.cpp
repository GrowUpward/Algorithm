/*
* 
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。时间复杂度为logn

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
    vector<int> searchInsert1(vector<int>& nums, int target)
    {
        int i = 0;
        vector<int> a(2,0);
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
    vector<int> searchInsert2(vector<int>& nums, int target) {
        
        if (target<nums[0] || target >nums[nums.size() - 1])
        {
            return { -1,-1 };
        }
        else {
            int leftBorder = searchLeftBorder(nums, target);
            int rightBorder = searchRightBorder(nums, target);
            return { leftBorder,rightBorder };
        }
        
    }
    int searchRightBorder(vector<int>& nums, int target)//寻找右边界
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)//只要target还有可能在右区域（=是为了确保找到后续的值，只找到一个值等于目标值时，我们不能立即停止搜索）
            {
                left = mid + 1;//左边界就一直向右区域移动
            }
            else //搜索值一旦超过target
            {
                right = mid - 1;//就马上回退,此时正是右边界
            }       
        }
        if (nums[right] != target) {//可能在数据中不存在target
            right = -1;
        }
        return right ;
           
    }
    int searchLeftBorder(vector<int>& nums, int target)//寻找左边界
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)//只要target还有可能在左区域（=是为了确保找到后续的值，只找到一个值等于目标值时，我们不能立即停止搜索）
            {
                right = mid - 1;//右边界就一直向左区域移动
            }
            else //搜索值一旦超过target
            {
                left = mid + 1;//就马上回退,此时正是左边界
            }
        }
        if (nums[left] != target) {//可能在数据中不存在target
            left = -1;
        }
        return left;

    }

};
int main()
{
    vector<int>nums;
    nums = { 5,7,7,8,8,10};
    int target =6;//[2,3]
    Solution s;
    vector<int> res;
    //res = s.searchInsert1(nums, target);
    res = s.searchInsert2(nums, target);
     cout << "[" << res[0] << "," << res[1] << "]" << endl;

}

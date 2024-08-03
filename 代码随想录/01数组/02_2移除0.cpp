#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0)
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        for (int i = slow++; i < nums.size(); i++)//再给后面的赋值
        {
            nums[i] = 0;
        }
    }
    void moveZeroes2(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0)
            {
                swap(nums[slow], nums[fast]);//直接交换
                slow++;
            }
        }
    }
};


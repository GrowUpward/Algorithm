/*
* 
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
����Լ������������ظ�Ԫ�ء�

ʾ�� 1:
����: [1,3,5,6], 5
���: 2

ʾ�� 2:
����: [1,3,5,6], 2
���: 1
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //������
    int searchInsert1(vector<int>& nums, int target) {
        int i = 0;
        for (i=0; i<nums.size(); i++)
        {

            //if (nums[i] < target)//ֻҪС��+
            //{
            //    cout << i<<" ooo" << endl;//��������
            //}
            //else
            //{
            //    return i;//=��>���صĽ��һ�������Ǵ�λ��
            //}
            if (nums[i] >= target)
            {
                return i;
            }
        }
        return i;
    }
    //���ַ�
    int searchInsert2(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right-left) / 2;
            if (target == nums[mid])
            {
                return mid;//�ҵ�����ȵ�
            }
            else if (target < nums[mid])
            {
                right = mid - 1;//�������
            }
            else//target >left
            {
                left = mid + 1;
            }
        }
        return left;//right+1 û�ҵ�������
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
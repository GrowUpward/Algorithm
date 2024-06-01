/*
* 
����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

��������в�����Ŀ��ֵ target������ [-1, -1]��

ʾ�� 1��

���룺nums = [5,7,7,8,8,10], target = 8
�����[3,4]
ʾ�� 2��

���룺nums = [5,7,7,8,8,10], target = 6
�����[-1,-1]
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //������
    int* searchInsert1(vector<int>& nums, int target)
    {
        int i = 0;
        int a[2];
        for (; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                a[0] = i;
                //2:=��3��=,���룬�ټ���һ��
                while (nums[i] == target && i < nums.size())
                {
                    i++;//ֱ���ҵ����һ����ȵ�
                }
                a[1] = i-1;//���һ�εȵ�ʱ�������ѭ�������ˣ�����Ҫ��ȥ
                return a;
            }
        }
        a[0] = a[1] = -1;
        return a;
    }
    //���ַ�
    int* searchInsert2(vector<int>& nums, int target) {
        int a[2];
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right-left) / 2;
            if (target == nums[mid])
            {
                return a;//�ҵ�����ȵ�
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
        return a;//right+1 û�ҵ�������
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
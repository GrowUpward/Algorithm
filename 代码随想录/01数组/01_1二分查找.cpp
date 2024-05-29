/*
����Ŀ����
����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��
дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1
������˼·������������������ģ�����ÿ��ֻȡ�����������м���Ǹ�ֵ����Ŀ��ֵ���жԱȣ�Ȼ������������䣬ֱ���ҵ�Ϊֹ
�������߼�����
��ȷ����ʼ�������䣺
��ʼλ�ã�left=0;
����λ�ã�right=size-1;
�м�ֵ��middle=left+(right-left)/2;
�ڲ���+������������
if nums[middle]>target=target:�ҵ�����
if nums[middle]<target��˵��target��middle�ұ�,��left=middle+11
if nums[middle]>target:˵��target��middle���,��right=middle-1
��ע�⡿��
һ��middle = (left + right) / 2������left + right���ܻ�������������
�ʻ��ֱ�﷽ʽ��middle=left+(right-left)/2;
�ο����ӣ�https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E6%80%9D%E8%B7%AF
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
			int middle = left + ((right - left) / 2);// ��ֹ(left + right) ��� ��ͬ��(left + right)/2
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
		return -1;//δ�ҵ�
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
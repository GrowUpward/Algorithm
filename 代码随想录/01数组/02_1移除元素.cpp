/*
����Ŀ��������һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³���
������˼·��������Ŀ��ֵ+
�������߼�����
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
			if (nums[i] == val)// ������Ҫ�Ƴ���Ԫ�أ��ͽ����鼯����ǰ�ƶ�һλ
			{
				for (int j = i+1; j < size; j++)
				{
					nums[j - 1] = nums[j];//Ԫ��ǰ��
					//nums[j] = nums[j + 1];//j���ܻ�Խ��

				}
				i--; // ��Ϊ�±�i�Ժ����ֵ����ǰ�ƶ���һλ������iҲ��ǰ�ƶ�һλ
				size--; // ��ʱ����Ĵ�С-1
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
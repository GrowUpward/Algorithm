//����һ�����ǵݼ�˳���������������nums������ÿ�����ֵ�ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�˳������
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums)
	{
		vector<int> b;
		int t = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			t = nums[i] * nums[i];
			b.push_back(t);
		}
		sort(b.begin(), b.end());//����
		return b;
	}

};
int main() {
	vector<int> a = { -4,-1,0,3,10 };
	Solution s;
	vector<int>b=s.sortedSquares(a);
	for (int i = 0; i < b.size(); i++)
		printf("%d ", b[i]);
	return 0;
}
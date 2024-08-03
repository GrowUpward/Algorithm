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
		sort(b.begin(), b.end());//¿ìÅÅ
		return b;
	}

};
int main()
{
	vector <int> a = { -4,-1,0,3,10 };
	Solution s;
	a = s.sortedSquares(a);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
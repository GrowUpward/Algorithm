//����һ������n���������������һ��������s���ҳ���������������͡�s�ĳ�����С�����������飬�������䳤�ȡ���������ڷ��������������飬����0��

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	int minSubArrayLen(int target, vector<int>&nums) {
		int minLength = INT32_MAX;
		int sum = 0;
		int i = 0;//����������ʼλ��
		int subLength = 0;//�������ڵĳ���
		for (int j = 0; j < nums.size(); j++)
		{
			sum += nums[j];
			//��ʱ����������
			while (sum >= target) {
				subLength = j - i + 1;//ȡ�Ӵ��ĳ���
				minLength = minLength < subLength ? minLength : subLength;
				
				//sum -= nums[i++];// �������ֳ��������ڵľ���֮�������ϱ��i�������е���ʼλ�ã�
				sum -= nums[i];//��һ���ĺ�
				i++;//��ʼλ��������
			}
		}
		// ���resultû�б���ֵ�Ļ����ͷ���0��˵��û�з���������������
		return minLength == INT32_MAX ? 0 : minLength;
	}
};
int main() {
	vector<int> a = { 2,3,1,2,4,3 };
	int target = 7;
	Solution s;
	int b = s.minSubArrayLen(target,a);
	printf("%d", b);
	return 0;
}
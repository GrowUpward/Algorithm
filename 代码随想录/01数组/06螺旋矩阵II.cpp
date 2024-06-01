/*
����Ŀ����59.��������II
����һ�������� n������һ������ 1 �� n^2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е������ξ���
������˼·����
ģ��˳ʱ�뻭����Ĺ���:

������д�����
������д��ϵ���
������д��ҵ���
������д��µ���
��������һȦһȦ��ô����ȥ��
https://code-thinking-1253855093.file.myqcloud.com/pics/20220922102236.png
�������߼�������ʼһ����ά����+��䣺
������ıߣ�
����i=0;j=0��i��ʾ�У�j��ʾ��
�ϣ�i���䣬j++,�Ӷ��٣�n-1,���i=0,j=2
�ң�j���䣬i++,�Ӷ��٣�n-1,���i=2,j=2
�£�i���䣬j--,�����٣�n-1,���i=2,j=0
��j���䣬i--,�����٣�n-1,���i=0,j=0
���������
���nΪ�����Ļ�����Ҫ�������������м��λ�ø�ֵ

��ע�⡿��
���ѭ��������ԭ�򣬼����ÿ��������ҿ���ԭ��
�ο����ӣ�https://programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));// ʹ��vector����һ����ά����
		int startx = 0, starty = 0;
		int loop = n / 2;// ÿ��Ȧѭ�����Σ�����nΪ����3����ôloop = 1 ֻ��ѭ��һȦ�������м��ֵ��Ҫ��������
		int mid = n / 2;// �����м��λ�ã����磺nΪ3�� �м��λ�þ���(1��1)��nΪ5���м�λ��Ϊ(2, 2)
		int count = 1; // ������������ÿһ���ո�ֵ
		int offset = 1;// ��Ҫ����ÿһ���߱����ĳ��ȣ�ÿ��ѭ���ұ߽�����һλ
		int i, j;
		while (loop--) {
			i = startx;
			j = starty;
			// ���濪ʼ���ĸ�for����ģ��ת��һȦ
			// ģ��������д�����(����ҿ�)
			for (j; j < n - offset; j++) {
				res[i][j] = count++;
			}
			// ģ��������д��ϵ���(����ҿ�)
			for (i; i < n - offset; i++) {
				res[i][j] = count++;
			}
			// ģ��������д��ҵ���(����ҿ�)
			for (j; j > starty; j--) {
				res[i][j] = count++;
			}
			// ģ��������д��µ���(����ҿ�)
			for (i; i > startx; i--) {
				res[i][j] = count++;
			}

			// �ڶ�Ȧ��ʼ��ʱ����ʼλ��Ҫ���Լ�1�� ���磺��һȦ��ʼλ����(0, 0)���ڶ�Ȧ��ʼλ����(1, 1)
			startx++;
			starty++;

			// offset ����ÿһȦ��ÿһ���߱����ĳ���
			offset += 1;

			// ���nΪ�����Ļ�����Ҫ�������������м��λ�ø�ֵ
			if (n % 2) {
				res[mid][mid] = count;
			}
			return res;
		}
	}
};
int main()
{
	int n = 3;
	Solution s;
	vector<vector<int>>a = s.generateMatrix(n);
	for (int i = 0; i < a[0].size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			printf("%d ", a[i][j]);
		}
		cout << endl;
	}
}
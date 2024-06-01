/*
【题目】：59.螺旋矩阵II
给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
【解题思路】：
模拟顺时针画矩阵的过程:

填充上行从左到右
填充右列从上到下
填充下行从右到左
填充左列从下到上
由外向内一圈一圈这么画下去。
https://code-thinking-1253855093.file.myqcloud.com/pics/20220922102236.png
【代码逻辑】：初始一个二维数组+填充：
①填充四边：
首先i=0;j=0，i表示行，j表示列
上：i不变，j++,加多少？n-1,最后：i=0,j=2
右：j不变，i++,加多少？n-1,最后，i=2,j=2
下：i不变，j--,减多少？n-1,最后，i=2,j=0
左：j不变，i--,减多少？n-1,最后，i=0,j=0
②填充中心
如果n为奇数的话，需要单独给矩阵最中间的位置赋值

【注意】：
坚持循环不变量原则，即坚持每条边左闭右开的原则
参考链接：https://programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));// 使用vector定义一个二维数组
		int startx = 0, starty = 0;
		int loop = n / 2;// 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
		int mid = n / 2;// 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
		int count = 1; // 用来给矩阵中每一个空格赋值
		int offset = 1;// 需要控制每一条边遍历的长度，每次循环右边界收缩一位
		int i, j;
		while (loop--) {
			i = startx;
			j = starty;
			// 下面开始的四个for就是模拟转了一圈
			// 模拟填充上行从左到右(左闭右开)
			for (j; j < n - offset; j++) {
				res[i][j] = count++;
			}
			// 模拟填充右列从上到下(左闭右开)
			for (i; i < n - offset; i++) {
				res[i][j] = count++;
			}
			// 模拟填充下行从右到左(左闭右开)
			for (j; j > starty; j--) {
				res[i][j] = count++;
			}
			// 模拟填充左列从下到上(左闭右开)
			for (i; i > startx; i--) {
				res[i][j] = count++;
			}

			// 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
			startx++;
			starty++;

			// offset 控制每一圈里每一条边遍历的长度
			offset += 1;

			// 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
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
/*
x 的平方根 
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
【解题思路】：由于不能调用函数，要自己写，那就用搜索法，且可以用二分搜索法的”左闭右闭“，先从中间开始找，初始的搜索区间为[0,x]，若x是整数的平方，找到了就是找到了，但若x不是整数的平方，跳出循环，right<left,且right+1=left,此时应返回小的即right。
*/
class Solution {
public:
    int mySqrt(int x) {
        int left=0;
        int right=x;
        int middle = 0;
        while (left <= right)
        {
            middle = left + (right - left) / 2;

            if ((long long)middle * middle > x)
            {
                right = middle - 1;
            }
            else if ((long long)middle * middle < x)
            {
                left = middle + 1;
            }
            else // (middle^2==x)
            {
                return middle;
            }
        }
        return right;
    }
};


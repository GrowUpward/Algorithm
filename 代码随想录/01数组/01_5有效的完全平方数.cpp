/*
给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。

不能使用任何内置的库函数，如  sqrt 。
*/
class Solution {
public:
    bool isPerfectSquare(int x) {
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
                // return middle;
                return true;
            }
        }
        return false;
    }
};

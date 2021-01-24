/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long N = n;
        bool flag = false;
        if (N < 0) {
            flag = true;
            N = -N;
        }
        for (; N != 0; N >>= 1) {
            if (N & 1) ans *= x;
            x = x * x;
        }
        return flag ? 1.0 / ans : ans;
    }
};
// @lc code=end


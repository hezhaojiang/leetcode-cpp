/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1.0 / (x * myPow(x, -(n + 1)));
        if (n == 0) return 1;
        double ans = myPow(x, n >> 1);;
        return ans * ans * ((n & 1) ? x : 1);
    }
};
// @lc code=end

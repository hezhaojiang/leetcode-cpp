/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        int index2 = 0, index3 = 0, index5 = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = min(min(dp[index2] * 2, dp[index3] * 3), dp[index5] * 5);
            if (dp[i] == 2 * dp[index2]) index2++;
            if (dp[i] == 3 * dp[index3]) index3++;
            if (dp[i] == 5 * dp[index5]) index5++;
        }
        return dp[n - 1];
    }
};
// @lc code=end

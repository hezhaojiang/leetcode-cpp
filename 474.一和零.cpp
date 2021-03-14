/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include <numeric>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int one = 0, zero = 0;
        for (auto c : strs[0])
            if (c == '0') zero++;
            else one++;
        dp[0][0] = 0;
        for (int x = m; x >= 0; x--) for (int y = n; y >= 0; y--) {
            if (zero <= x && one <= y) dp[x][y] = 1;
        }
        for (int i = 1; i < strs.size(); i++) {
            one = zero = 0;
            for (auto c : strs[i])
                if (c == '0') zero++;
                else one++;
            for (int x = m; x >= zero; x--) for (int y = n; y >= one; y--) {
                dp[x][y] = max(dp[x][y], dp[x - zero][y - one] + 1);
            }
        }
        int res = 0;
        for (int x = m; x >= 0; x--) for (int y = n; y >= 0; y--) {
            res = max(res, dp[x][y]);
        }
        return res;
    }
};
// @lc code=end

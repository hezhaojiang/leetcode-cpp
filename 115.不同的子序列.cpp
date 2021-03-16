/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
typedef long long llint;
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<llint>> dp(m + 1, vector<llint>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
            for (int j = 0; j < n; j++) {
                if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];
                else dp[i + 1][j + 1] = dp[i][j + 1];
            }
        }
        return dp.back().back();
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        // s 的前 i 字符能否匹配 p 的前 j 字符
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        int index = 0;
        while (p[index] == '*') dp[0][++index] = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] == p[j] || p[j] == '?') dp[i + 1][j + 1] = dp[i][j];
                else if (p[j] == '*') dp[i + 1][j + 1] = dp[i][j + 1] | dp[i + 1][j];
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

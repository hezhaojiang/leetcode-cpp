/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isMatch(string &s, string &p) {
        int m = s.length();
        int n = p.length();
        // s 的前 i 字符能否匹配 p 的前 j 字符
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        int index = 1;
        while (index < n && p[index] == '*') {
            dp[0][index + 1] = true;
            index += 2;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] == p[j] || p[j] == '.')
                    dp[i + 1][j + 1] = dp[i][j];
                else if (p[j] == '*') {
                    dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i + 1][j - 1];
                    if (s[i] == p[j - 1] || p[j - 1] == '.') dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i][j + 1];
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

int main() {
    Solution solve;
    string s = "aa";
    string p = "a*";
    // Testcase: ""bccbcccbcbbbcbb"\n"c*c*c*c*c*.*.*b*b*""
    solve.isMatch(s, p);
    return 0;
}

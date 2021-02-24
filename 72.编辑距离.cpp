/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        // word1 的前 i 字符转换为 word2 的前 j 字符的最少操作数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int i = 0; i <= n; i++) dp[0][i] = i;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word1[i] == word2[j]) dp[i + 1][j + 1] = dp[i][j];
                else dp[i + 1][j + 1] = 1 + min(min(dp[i][j], dp[i + 1][j]), dp[i][j + 1]);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

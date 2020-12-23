/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int L1 = word1.length();
        int L2 = word2.length();
#if 0
        // s1 到第 i 个位置为止， s2 到第 j 个位置为止的最长公共子序列
        vector<vector<int>> dp(L1 + 1, vector<int>(L2 + 1, 0));
        for (int i = 0; i < L1; i++) {
            for (int j = 0; j < L2; j++) {
                if (word1[i] == word2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return L1 + L2 - 2 * dp[L1][L2];
#endif
        // s1 到第 i 个位置为止， s2 到第 j 个位置为止的最少删除次数
        vector<vector<int>> dp(L1 + 1, vector<int>(L2 + 1, 0));
        for (int i = 0; i <= L1; i++) {
            for (int j = 0; j <= L2; j++) {
                if (i == 0 || j == 0) dp[i][j] = i + j;
                else if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp[L1][L2];
    }
};
// @lc code=end


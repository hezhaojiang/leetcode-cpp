/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0; i < len1; i++) for (int j = 0; j < len2; j++) {
            if (text1[i] == text2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
        return dp[len1][len2];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int N = s.length();
        int maxLength = 0;
        vector<int> dp(N + 1, 0);
        for (int i = 1; i < N; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') dp[i + 1] = dp[i - 1] + 2;
                else if (i - dp[i] > 0 && s[i - dp[i] - 1] == '(') dp[i + 1] = dp[i] + 2 + dp[i - dp[i] - 1];
                else dp[i + 1] = 0;
                maxLength = max(maxLength, dp[i + 1]);
            }
        }
        return maxLength;
    }
};
// @lc code=end


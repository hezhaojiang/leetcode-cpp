/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.length();
        if (s.empty()) return 0;
#if 1
        vector<vector<int>> dp(N, vector<int>(N, 1));
        for (int d = 1; d < N; d++) for (int i = 0; i + d < N; i++) {
            if (d == 1) dp[i][i + d] = s[i] == s[i + d] ? 2 : 1;
            else {
                if (s[i] == s[i + d]) dp[i][i + d] = dp[i + 1][i + d - 1] + 2;
                else dp[i][i + d] = max(dp[i][i + d - 1], dp[i + 1][i + d]);
            }
        }
        return dp[0][N - 1];
    }
#else
        return longestPalindromeSubseq(s, 0, N - 1);
    }

    int longestPalindromeSubseq(string &s, int start, int end) {
        if (start == end) return 1;
        if (start + 1 == end) return 1 + (s[start] == s[end]);
        if (s[start] == s[end]) return longestPalindromeSubseq(s, start + 1, end - 1) + 2;
        return max(longestPalindromeSubseq(s, start, end - 1), longestPalindromeSubseq(s, start + 1, end));
    }
#endif
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int N = s.length();
        if (N == 0 || s[0] == '0') return 0;
        vector<int> dp(N + 1, 1);
        for (int i = 1; i < N; i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') dp[i + 1] = dp[i - 1];
                else return 0;
            }
            else if (s[i - 1] == '1') dp[i + 1] = dp[i] + dp[i - 1];
            else if (s[i - 1] == '2' && s[i] < '7') dp[i + 1] = dp[i] + dp[i - 1];
            else dp[i + 1] = dp[i];
        }
        return dp.back();
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    solve.numDecodings("10");
    return 0;
}

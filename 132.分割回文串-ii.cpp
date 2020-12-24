/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void getO_Obymid(vector<vector<int>> &is, string &s, int midl, int midr, int len) {
        while (midl >= 0 && midr < len) {
            if (s[midl] == s[midr]) is[midl--][midr++] = 1;
            else { is[midl--][midr++] = 0; break; }
        }
    }
    int minCut(string s) {
        int N = s.length();
        vector<vector<int>> isO_O(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            getO_Obymid(isO_O, s, i, i, N);
            getO_Obymid(isO_O, s, i, i + 1, N);
        }

        vector<int> dp(N + 1, INT_MAX);
        dp[0] = -1;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) 
                if (isO_O[i][j] == 1) dp[j + 1] = min(dp[i] + 1, dp[j + 1]);
        }
        return dp.back();
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    solve.minCut("cabababcbc");
    return 0;
}

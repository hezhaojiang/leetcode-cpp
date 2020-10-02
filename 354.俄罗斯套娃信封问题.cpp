/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), 
            [&](auto& a, auto& b) { return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); });
        int N = envelopes.size();
        int maxEnvelope = 1;
        vector<int> dp(N, 1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) 
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxEnvelope = max(maxEnvelope, dp[i]);
        }
        return maxEnvelope;
    }
};
// @lc code=end


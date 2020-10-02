/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxLIS = 1;
        int maxlisCount = 0;
        int N = nums.size();
        vector<vector<int>> dp(N, {1, 1});
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++)
                if (nums[i] > nums[j]) {
                    if (dp[j][0] + 1 > dp[i][0]) { dp[i][0] = dp[j][0] + 1; dp[i][1] = dp[j][1]; }
                    else if  (dp[j][0] + 1 == dp[i][0]) dp[i][1] += dp[j][1];
                }
            if (dp[i][0] > maxLIS) maxLIS = dp[i][0];
        }
        for (auto & lis : dp) if (lis[0] == maxLIS) maxlisCount += lis[1];
        return maxlisCount;
    }
};
// @lc code=end


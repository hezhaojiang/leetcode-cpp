/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxLIS = 1;
        int N = nums.size();
        vector<int> dp(N, 1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j]) dp[i] = max(dp[j] + 1, dp[i]);
            maxLIS = max(maxLIS, dp[i]);
        }
        return maxLIS;
    }
};
// @lc code=end


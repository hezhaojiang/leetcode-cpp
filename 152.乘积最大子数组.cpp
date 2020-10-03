/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int N = nums.size();
        int maxPro = nums[0];
        vector<vector<int>> dp(N, {0,0});
        for (int i = 0; i < N; i++) {
            dp[i][0] = dp[i][1] = nums[i];
            if (i != 0 && nums[i] != 0) {
                if (nums[i] > 0) {
                    dp[i][1] = max(dp[i][1], nums[i] * dp[i - 1][1]);
                    dp[i][0] = min(dp[i][0], nums[i] * dp[i - 1][0]);
                }
                else {
                    dp[i][1] = max(dp[i][1], nums[i] * dp[i - 1][0]);
                    dp[i][0] = min(dp[i][0], nums[i] * dp[i - 1][1]);
                }
            }
            maxPro = max(maxPro, dp[i][1]);
        }
        return maxPro;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        else sum >>= 1;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        if (nums[0] <= sum) dp[nums[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]]; // 选择
            }
        }
        return dp.back();
    }
};
// @lc code=end

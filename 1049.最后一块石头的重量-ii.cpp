/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum >> 1;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        if (stones[0] <= target) dp[stones[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = dp[j] || dp[j - stones[i]]; // 选择
            }
        }
        for (int i = target; i >= 0; i--) {
            if (dp[i]) return sum - 2 * i;
        };
        return 0;
    }
};
// @lc code=end


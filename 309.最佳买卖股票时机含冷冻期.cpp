/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][j] - 第 i 天的最大利润
        // dp[i][0] - 手里有股票
        // dp[i][1] - 手里没有股票 在冷冻期
        // dp[i][2] - 手里没有股票 不在冷冻期
        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MIN));
        dp[0][2] = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i][2] != INT_MIN) { // 手里没有股票 不在冷冻期
                // 买
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][2] - prices[i]);
                // 不买
                dp[i + 1][2] = max(dp[i + 1][2], dp[i][2]);
            }
            if (dp[i][0] != INT_MIN) { // 手里有股票
                // 卖
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + prices[i]);
                // 不卖
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
            }
            if (dp[i][1] != INT_MIN) { // 手里没有股票 在冷冻期
                // 不能买卖
                dp[i + 1][2] = max(dp[i + 1][2], dp[i][1]);
            }
        }
        return max(dp[n][1], dp[n][2]);
    }
};
// @lc code=end

int main()
{
    Solution solve;
    vector<int> prices{1,2,3,0,2};
    solve.maxProfit(prices);
    return 0;
}

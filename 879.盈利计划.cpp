/*
 * @lc app=leetcode.cn id=879 lang=cpp
 *
 * [879] 盈利计划
 */
#include <vector>
using namespace std;
// @lc code=start
#define MOD 1000000007
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int count = group.size();
        // dp[i][j] 代表 i 个人产生大于等于 j 利润的方案数
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1; // 初始化单个利润为0时的情况
        for (int i = 0; i < count; i++) {
            int p = profit[i], g = group[i];
            for (int j = n; j >= g; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    dp[j][k] = (dp[j][k] + dp[j - g][max(k - p, 0)]) % MOD;
                }
            }
        }
        return dp.back().back();
    }
};
// @lc code=end
